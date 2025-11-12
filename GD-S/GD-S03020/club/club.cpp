#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int T,n;
vector<int>a[5];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)a[i].clear();
		int x;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>x;
				a[i].push_back(x);
			}
		}
		int ans=0,tn=n;
		int cnt[5]={0,0,0,0,0};
		for(int i=1;;i+=2){
			if(tn==0)break;
			tn-=2;
			int maxn=-1,numj=-1,numk=-1;
			for(int j=0;j<3;j++){
				if(cnt[j]==(n>>1))continue;
				cnt[j]++;
				for(int k=0;k<3;k++){
					if(cnt[k]==(n>>1))continue;
					if(a[i][j]+a[i+1][k]>maxn){
						maxn=a[i][j]+a[i+1][k];
						numj=j;
						numk=k;
					}
				}
				cnt[j]--;
			}
			ans+=maxn;
			cnt[numj]++;
			cnt[numk]++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
