#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100100;
int T,n,a[N][4],b[N][4],c[N][4];
int cnt[4],id;
int num[4][N];
bool cmp(int x,int y){
	return (b[x][1]-b[x][2])>(b[y][1]-b[y][2]);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i][1]=a[i][1]; c[i][1]=1;
			b[i][2]=a[i][2]; c[i][2]=2;
			b[i][3]=a[i][3]; c[i][3]=3;
			if(b[i][1]<b[i][2]) swap(b[i][1],b[i][2]),swap(c[i][1],c[i][2]);
			if(b[i][2]<b[i][3]) swap(b[i][2],b[i][3]),swap(c[i][2],c[i][3]);
			if(b[i][1]<b[i][2]) swap(b[i][1],b[i][2]),swap(c[i][1],c[i][2]);
			cnt[c[i][1]]++;
			num[c[i][1]][cnt[c[i][1]]]=i;
			//cout<<i<<' '<<a[i][1]<<' '<<a[i][2]<<' '<<a[i][3]<<' '<<b[i][1]<<' '<<b[i][2]<<' '<<b[i][3]<<'\n';
			//cout<<c[i][1]<<' '<<c[i][2]<<' '<<c[i][3]<<'\n';
			//cout<<cnt[1]<<' '<<cnt[2]<<' '<<cnt[3]<<'\n';
		}
		//cout<<cnt[1]<<' '<<cnt[2]<<' '<<cnt[3]<<'\n';
		if(cnt[1]>=cnt[2] && cnt[1]>=cnt[3]) id=1;
		if(cnt[2]>=cnt[1] && cnt[2]>=cnt[3]) id=2;
		if(cnt[3]>=cnt[1] && cnt[3]>=cnt[2]) id=3;
		sort(num[id]+1,num[id]+1+cnt[id],cmp);
		int ans=0;
		for(int i=n/2+1;i<=cnt[id];i++) ans-=(b[num[id][i]][1]-b[num[id][i]][2]);
		//cout<<' '<<ans<<'\n';
		for(int i=1;i<=3;i++){
			//for(int j=1;j<=cnt[i];j++) cout<<num[i][j]<<' ';
			//cout<<'\n';
			for(int j=1;j<=cnt[i];j++) ans+=b[num[i][j]][1];
		}
		cout<<ans<<'\n';
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
