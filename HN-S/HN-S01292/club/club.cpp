#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100010][5],sx[5],wh,sz[5],mx,as;
priority_queue<int>p[5];
bool cmp(int x,int y){
	return a[wh][x]>a[wh][y];
}
void MAIN()
{
	as=sz[1]=sz[2]=sz[3]=0;
	for(int i=1;i<=3;i++){
		while(p[i].empty()==0){
			p[i].pop();
		}
	}
	int n,as=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		sx[1]=1;
		sx[2]=2;
		sx[3]=3;
		wh=i;
		sort(sx+1,sx+4,cmp);
		as+=a[i][sx[1]];
		sz[sx[1]]++;
		p[sx[1]].push(a[i][sx[2]]-a[i][sx[1]]);
	}
	mx=n/2;
	for(int i=1;i<=3;i++){
		while(sz[i]>mx){
			as+=p[i].top();
			p[i].pop();
			sz[i]--;
		}
	}
	cout<<as<<'\n';
	return;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		MAIN();
	}
	return 0;
}

