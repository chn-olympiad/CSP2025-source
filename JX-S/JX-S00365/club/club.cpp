#include<bits/stdc++.h>
using namespace std;
int n,T,cnt;
int a[500001][4];
int bj[18][4];
int a1[500001];
int sa2,sa23;
int mans;
void dfs(int s,int d1,int d2,int d3){
	if(s==n+1){
		if(d1>n/2||d2>n/2||d3>n/2){
			return;
		}
		else{
			for(int i=1;i<=n;i++){
				cnt+=a[i][1]*bj[i][1]+a[i][2]
				*bj[i][2]+a[i][3]*bj[i][3];
			}
			mans=max(mans,cnt);
			cnt=0;
			return;
		}
	}
	bj[s][1]=1;
	dfs(s+1,d1+1,d2,d3);
	bj[s][1]=0;
	bj[s][2]=1;
	dfs(s+1,d1,d2+1,d3);
	bj[s][2]=0;
	bj[s][3]=1;
	dfs(s+1,d1,d2,d3+1);
	bj[s][3]=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int x=1;x<=T;x++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			sa2+=a[i][2];
			sa23+=a[i][2]+a[i][3];
			a1[i]=a[i][1];
		}
		if(n<=17){
			dfs(1,0,0,0);
			cout<<mans<<endl;
		}
		else if(sa23==0){
			sort(a1+1,a1+n+1);
			for(int i=n;i>=n/2+1;i--){
				mans+=a1[i];
			}
			cout<<mans<<endl;
		}
		else{
			for(int i=1;i<=n;i++){
				mans+=max(max(a[i][1]
				,a[i][2]),a[i][3]);
			}
			cout<<mans<<endl;
		}
		for(int i=1;i<=n;i++){
			a[i][1]=0;
			a[i][2]=0;
			a[i][3]=0;
			a1[i]=0;
		}
		for(int i=1;i<=17;i++){
			bj[i][1]=0;
			bj[i][2]=0;
			bj[i][3]=0;
		}
		sa2=0;
		sa23=0;
		mans=0;
	}
	return 0;
}
