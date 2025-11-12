#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f
#define endl '\n'
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int t,n,a[100005][5],cnt[5],sum,m[100005],c[5][100005],k,id;
bool cmp(int x,int y){
	return a[x][id]-a[x][m[x]]<a[y][id]-a[y][m[y]];
}
signed main(){
	IOS
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(cnt,0,sizeof(cnt));
		sum=0,k=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int maxx=0,maxx2=0,maxn=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>maxx){
					maxx=a[i][j];
					m[i]=maxn;
					maxn=j;
				}
				else if(a[i][j]>maxx2){
					maxx2=a[i][j];
					m[i]=j;
				}
			}
			cnt[maxn]++;
			sum+=maxx;
			c[maxn][cnt[maxn]]=i;
		}
		id=0;
		for(int i=1;i<=3;i++) if(cnt[i]>n/2) id=i;
		if(id==0){
			cout<<sum<<endl;
			continue;
		}
		sort(c[id]+1,c[id]+1+cnt[id],cmp);
		for(int i=1;i<=cnt[id]-n/2;i++){
			int x=c[id][i];
			sum+=(a[x][m[x]]-a[x][id]);
		}
		cout<<sum<<endl;
	}
	return 0;
}
