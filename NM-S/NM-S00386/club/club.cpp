#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef pair<int,int> pll;
int t;
int cnt[]={0,0,0,0};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(cnt,0,sizeof cnt);
		int n;
		long res=0;
		cin>>n;
		int m=n/2;
		priority_queue<int,vector<int>,greater<int> >h[4];
		for(int i=1;i<=n;i++){
			pll f[4];
			for(int j=1;j<=3;j++){
				cin>>f[j].first;
				f[j].second=j;
			}
			sort(f+1,f+4);
			int mm=f[3].first,mp=f[3].second;
			int delta=mm-f[2].first;
			res+=mm;
			h[mp].push(delta);
			cnt[mp]++;
			if(cnt[mp]>m){
				cnt[mp]--;
				int minny=h[mp].top();
				h[mp].pop();
				res-=minny;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
