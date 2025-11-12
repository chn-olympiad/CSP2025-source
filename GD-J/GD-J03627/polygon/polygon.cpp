#include<bits/stdc++.h>
using namespace std;
long long num=0,n;
int x,d=0,f=0;
int a[10001],ba[10001];
void sum(int bian,int z,int bg,int s,int tm,int h){
	int g;
	for(int i=0;i<f;i++){
		if(bg==0){
			g=0;
			break;
		}
		if(bg==a[i]){
			g=i;
			break;
		}
	}
	if(bian<s){
		if(z>bg*2){
			num+=tm;
		}
	}
	else if(g==f-1){
		if(h+s>=bian){
			sum(bian,z+a[f-1],a[f-1],s+1,tm,h-1);
		}
	}
	else{
		for(int i=g+1;i<f;i++){
			sum(bian,z+a[i],a[i],s+1,tm*ba[a[i]],ba[a[i]]-1);
		}
		if(h>0){
			if(h>1){
			    sum(bian,z+a[g],bg,s+1,tm*h/2,h-1);
			}
			else{
				sum(bian,z+a[g],bg,s+1,tm*h,h-1);
			}
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		d=0;
		cin>>x;
		ba[x]++;
		for(int j=0;j<f;j++){
			if(x==a[j]){
				d+=1;
			}
		}
		if(d==0){
			a[f]=x;
			f++;
		}
	} 
	sort(a,a+f);
	for(int i=3;i<=n;i++){
		sum(i,0,0,1,1,0);
	}
	cout<<num;
	return 0;
} 
