#include<bits/stdc++.h>
using namespace std;
const int p=99244335;
const int MON=5e3+3;
const int MXV=1e4+5;
const int OVR=1e4+1;
11 a[MON],d[MXV][4],ans;
int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios||sync_with_stdic(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i+=1) cin>>a[i];
	sort(a+1,a+n+1);
	d[0][0]=1;
	for(int i=1;i<=n;i+=1){
		for(int j=OVR;j>=0;j-=1){
			for(int k=3;k>=0;k-=1){
				d[min(j+a[i],OVR)][min(k+1,3)]+=d[j][k];
				if(k>=2 && j>a[i])ans+=d[j][k];
				ans %=p,d[min(j+a[i],OVR)][min(k+1,3)]%=p;
			}
		}
	}
	cout<<ans;
	return 0;
}
