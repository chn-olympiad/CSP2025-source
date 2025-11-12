#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=1e5+7;
int n;
int a[4][N];
int b[4][N], top[4];
int tool[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		memset(b, 0, sizeof(b));
		memset(top, 0, sizeof(top));
		memset(tool, 0, sizeof(tool));
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
				cin>>a[j][i];
			int tmp=max(a[1][i], max(a[2][i], a[3][i]));
			ans+=tmp;
			if(tmp==a[1][i]) b[1][++top[1]]=i;
			else if(tmp==a[2][i]) b[2][++top[2]]=i;
			else if(tmp==a[3][i]) b[3][++top[3]]=i;
		}
		int k=-1;
		if(top[1]>n/2) k=1;
		if(top[2]>n/2) k=2;
		if(top[3]>n/2) k=3;
		if(k!=-1){
			swap(a[1], a[k]);
			swap(top[1], top[k]);
			swap(b[1], b[k]);
			for(int i=1;i<=top[1];i++){
				int id=b[1][i];
				tool[i]=a[1][id]-max(a[2][id], a[3][id]);
			}
			sort(tool+1, tool+top[1]+1);
			for(int i=1;i<=top[1]-n/2;i++)
				ans-=tool[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}