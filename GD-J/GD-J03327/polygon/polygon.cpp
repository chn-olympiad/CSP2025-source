#include<iostream>
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int a[1145140];
int sanb3(int a1,int a2,int a3){
	if(a1+a2+a3>a3*2)return 1;
	return 0;
}
int sanb4(int s1,int s2,int s3,int s4){
	if(s1+s2+s3+s4>s4*2)return 1;
	return 0;
}
int sanb5(int d1,int d2,int d3,int d4,int d5){
	if(d1+d2+d3+d4+d5>d5*2)return 1;
	return 0;
}
int sanb6(int d1,int d2,int d3,int d4,int d5,int d6){
	if(d1+d2+d3+d4+d5+d6>d6*2)return 1;
	return 0;
}
int sanb7(int d1,int d2,int d3,int d4,int d5,int d6,int d7){
	if(d1+d2+d3+d4+d5+d6+d7>d7*2)return 1;
	return 0;
}
int sanb8(int d1,int d2,int d3,int d4,int d5,int d6,int d7,int d8){
	if(d1+d2+d3+d4+d5+d6+d7+d8>d8*2)return 1;
	return 0;
}
int sanb9(int d1,int d2,int d3,int d4,int d5,int d6,int d7,int d8,int d9){
	if(d1+d2+d3+d4+d5+d6+d7+d8+d9>d9*2)return 1;
	return 0;
} 
int sanb10(int d1,int d2,int d3,int d4,int d5,int d6,int d7,int d8,int d9,int d10){
	if(d1+d2+d3+d4+d5+d6+d7+d8+d9+d10>d10*2)return 1;
	return 0;
}
int sanb(int a1,int a2,int a3,int k,int n1){
	if(a3>k)return sanb(a1,a2+1,a2+1,k,n1);
	if(a2>k-1)return sanb(a1+1,a1+1,a3,k,n1);
	if(a1>k-2)return n1;
	if(a[a1]+a[a2]+a[a3]>a[a3]*2&&a1!=a2&&a2!=a3&&a3!=a1){
		return sanb(a1,a2,a3+1,k,n1+1);
	}
	else return sanb(a1,a2,a3+1,k,n1);
} 
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);cout.tie(0); 
	int n,num=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	num+=sanb(1,2,3,n,0);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					num+=sanb4(a[i],a[j],a[k],a[l]);
					for(int m=l+1;m<=n;m++){
						num+=sanb5(a[i],a[j],a[k],a[l],a[m]);
						for(int q1=m+1;q1<=n;q1++){
							num+=sanb6(a[i],a[j],a[k],a[l],a[m],a[q1]);
							for(int q2=q1+1;q2<=n;q2++){
								num+=sanb7(a[i],a[j],a[k],a[l],a[m],a[q1],a[q2]);
								for(int q3=q2+1;q3<=n;q3++){
									num+=sanb8(a[i],a[j],a[k],a[l],a[m],a[q1],a[q2],a[q3]);
									for(int q4=q3+1;q4<=n;q4++){
										num+=sanb9(a[i],a[j],a[k],a[l],a[m],a[q1],a[q2],a[q3],a[q4]);
										for(int sb=q4;sb<=n;sb++){
											num+=sanb10(a[i],a[j],a[k],a[l],a[m],a[q1],a[q2],a[q3],a[q4],a[sb]);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	cout<<num;
	return 0;
}
