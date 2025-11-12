#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[500000][10];
int x[500000];
int y[500000];
int z[500000];
int pd[500000];
int t,u;int n,ans;
int sum[5];
void csh(){
	for(int i=1;i<=3;i++){
		sum[i]=0;
	}
	ans=0;t=0;
}
void cl(int k){
	for(int i=1;i<=n;i++){
		if(x[i]==k){
			t++;
			pd[t]=a[i][4];
		}
	}
	sort(pd+1,pd+t+1);
	u=sum[k]-(n/2);
	for(int i=1;i<=u;i++){
		ans-=pd[i];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
int T;
cin>>T;
for(int p=1;p<=T;p++){
	cin>>n;u=0;
	csh();
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][1]>=a[i][2]){
			if(a[i][1]>=a[i][3]){
				if(a[i][2]>=a[i][3]){
					x[i]=1;y[i]=2;z[i]=3;
				}
				else{
					x[i]=1;y[i]=3;z[i]=2;
				}
			}
			else{
				x[i]=3;y[i]=1;z[i]=2;
			} 
		}
		else{
			if(a[i][2]>=a[i][3]){
				if(a[i][1]>=a[i][3]){
					x[i]=2;y[i]=1;z[i]=3;
				}
				else{
					x[i]=2;y[i]=3;z[i]=1;
				}
			}
			else{
				x[i]=3;y[i]=2;z[i]=1;
			} 
		}
		a[i][4]=a[i][x[i]]-a[i][y[i]];
	}
	for(int i=1;i<=n;i++){
		sum[x[i]]++;
		ans+=a[i][x[i]];
	}
	for(int k=1;k<=3;k++){
		if(sum[k]>(n/2)){
			cl(k);
		}
	}
	cout<<ans<<endl;
}
}