#include<bits/stdc++.h>
using namespace std;
int t,n;
int a1,b2,c3;
int club1[200005],club2[200005],club3[200005];
int a[200005],b[200005],c[200005];
int sum,cnt;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;//组数 
	for(int i=1;i<=t;i++){
		cin>>n;//人数 
		cnt=0;
		for(int j=1;j<=n;j++){ //对三个俱乐部的满意度 
			cin>>a[j]>>b[j]>>c[j];
			if(a[j]>b[j]){
				if(a[j]>c[j]){//取最大加入 ,记录 
					club1[j]++;
					a1++;
				}
				club3[j]++;  
				c3++;                                                                                                                                                                                                                                                     
			}
			else{
				club2[j]++;
				b2++;
			}
		}
		if(a1>n/2){
			for(int j=1;j<=n;j++){
				if(club1[j]!=0){
					if(b[j]>c[j]){
						club1[j]--;
						club2[j]++;
						a1--;
						b2++;
					}
					else{
						club1[j]--;
						club3[j]++;
						a1--;
						c3++;
					}
				}
			}
			if(a1==n/2)
				break;
		}
		if(b2>n/2){
			for(int j=1;j<=n;j++){
				if(club2[j]!=0){
					if(a[j]>c[j]){
						club2[j]--;
						club1[j]++;
						b2--;
						a1++;
					}
					else{
						club2[j]--;
						club3[j]++;
						b2--;
						c3++;
					}
				}
			}
			if(b2==n/2)
				break;
		}
		if(c3>n/2){
			for(int j=1;j<=n;j++){
				if(club3[j]!=0){
					if(a[j]>b[j]){
						club3[j]--;
						club1[j]++;
						c3--;
						a1++;
					}
					else{
						club3[j]--;
						club2[j]++;
						c3--;
						b2++;
					}
				}
			}
			if(c3==n/2)
				break;
		}
		for(int j=1;j<=n;j++){
			if(club1[j]!=0)
				cnt+=a[j];
			if(club2[j]!=0)
				cnt+=b[j];
			if(club3[j]!=0)
				cnt+=c[j];
		}
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
