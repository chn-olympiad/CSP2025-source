#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+9;
struct node{
	int q;
	int v;
	int w;
}s[maxn];

int a[maxn]; 

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin >> s[i].q >>s[i].v >>s[i].w ;
		ans+=s[i].w;
	}
	
	for(int i=1;i<=m;i++){
	    int flag=2;
		int c;
		cin >> c;
		if(c==0)
		for(int i=1;i<=n;i++){
			cin >> a[i];
	    }
	}
	cout <<ans<<endl;
	return 0;
}
