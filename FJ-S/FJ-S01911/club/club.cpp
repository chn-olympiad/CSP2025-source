#include<bits/stdc++.h>
using namespace std;

struct nd{
	int num;
	int cl1,cl2;
};

int t,n;
int a[100010][5];
nd de[100010];

bool cmp(nd x,nd y){
	return x.num>y.num;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		cin>>n;
		unsigned long long ans=0;
		for(int i=1;i<=n;++i){
			int maxn=1,minn=1;
			for(int j=1;j<=3;++j){
				cin>>a[i][j];
				if(a[i][maxn]<a[i][j]){
					maxn=j;
				}
				if(a[i][minn]>a[i][j]){
					minn=j;
				}
			}
			int midn=6-maxn-minn;
			ans+=a[i][midn];
			de[i].num=a[i][maxn]-a[i][midn];
			de[i].cl1=maxn;
			de[i].cl2=midn;
		}
		sort(de+1,de+n+1,cmp);
		int cnt[5]={0,0,0,0};
		for(int i=1;i<=n;++i){
			if(cnt[de[i].cl1]+1<=(n>>1)){
				cnt[de[i].cl1]++;
				ans+=de[i].num;
			}
			else{
				cnt[de[i].cl2]++;
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
