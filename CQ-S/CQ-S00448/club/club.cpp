#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int a[100010][3];
int b[100010][3];
int p[100010];
int c[3];
int ni;
bool cmp(int x,int y){
	return a[ni][x]>a[ni][y];
}
bool cp1(int x,int y){
	return a[x][b[x][0]]-a[x][b[x][1]]>a[y][b[y][0]]-a[y][b[y][1]];
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		for(int j=0;j<=2;j++){
			b[i][j]=j;
		}
		ni=i;
		sort(b[i],b[i]+3,cmp);
	}
	for(int i=1;i<=n;i++){
		p[i]=i;
	}
	sort(p+1,p+n+1,cp1);
	ll res=0;
	for(int xx=1;xx<=n;xx++){
		int i=p[xx];
		int tmp=b[i][0];
		if(c[tmp]==n/2)tmp=b[i][1];
		c[tmp]++;
		res+=a[i][tmp];
	}
	cout<<res<<"\n";
	c[0]=c[1]=c[2]=0;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tt;
	cin>>tt;
	while(tt--)solve();
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

18
4
13
*/
