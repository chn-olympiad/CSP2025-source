#include<bits/stdc++.h>
using namespace std;
#define M 2000005
#define ll long long
int a[1002][1002];
int l[M];
int b[M];
int q,w,e,pp;
int p;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++){
		for(int y=1;y<i;y++){
			a[y][i]=-1;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>q>>w>>e;
		if(q>w){
			int t=w;
			w=q;
			q=t;
		}
		if(a[q][w]<0){
			a[q][w]=e;
		}else{
			a[q][w]=min(a[q][w],e);
		}
	}
	for(int i=2;i<=n;i++){
		for(int y=1;y<i;y++){
			if(a[y][i]!=-1){
				b[++pp]=a[y][i];
			}
		}
	}
	int j=0;
	while(k--){
		cin>>l[k];
		if(l[k]==0){
			j=1;
		}
	}
	if(j==1){
		cout<<0;
		return 0;
	}
	sort(b,b+pp+1);
	for(int i=1;i<=n-2;i++){
		p+=b[i];
	}
	cout<<p;
	return 0;
}

