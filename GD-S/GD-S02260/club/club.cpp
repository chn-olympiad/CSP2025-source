#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;
const int N=1e5;
int n,a[N+5],b[N+5],c[N+5],t,ans1,ans2,ans3;
int bb[N+5],aa[N+5],cc[N+5];
int maxx=INT_MIN,sum=0,res=0;
void dfs(int x){
	if(x>n){
		for(int i=1;i<=n;i++){
			if(aa[i]==1){
				ans1++;
			}
			if(aa[i]==2){
				ans2++;
			}
			if(aa[i]==3){
				ans3++;
			}
		}
		if(ans1<=n/2&&ans2<=n/2&&ans3<=n/2){
				res++;
				sum=0;
				for(int i=1;i<=n;i++){
					sum+=bb[i];
				}
				cc[res]=sum;
		}
		ans1=0;
		ans2=0;
		ans3=0;
		return;
	} 
	for(int i=1;i<=3;i++){
		aa[x]=i;
		if(i==1) bb[x]=a[x];
		if(i==2) bb[x]=b[x];
		if(i==3) bb[x]=c[x];
		dfs(x+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(cc,0,sizeof(cc));
		maxx=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		dfs(1);
		for(int i=1;i<=res;i++){
		    if(maxx<cc[i]) maxx=cc[i];
	    }
	    cout<<maxx;
	}
	return 0;
}
