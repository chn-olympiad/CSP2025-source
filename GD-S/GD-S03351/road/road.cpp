#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
	}
	int cnt=0;
	for(int i=1;i<=k;i++){
		int l;
		cin>>l;
		for(int i=1;i<=n;i++){
			int q,w,e;
			cin>>q>>w>>e;
			cnt=cnt+q+w+e;
		}
	}
	cout<<cnt;
} 
