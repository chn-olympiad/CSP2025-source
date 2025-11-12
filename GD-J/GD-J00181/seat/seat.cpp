#include <bits/stdc++.h>
using namespace std;
int sz[110];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=(n*m);i++) cin>>sz[i];
	int cj=sz[1];
	sort(sz+1,sz+(n*m)+1,cmp);
	int index=1;
	for (int i=1;i<=(n*m);i++){
		if (sz[i]==cj){
			index=i;
			break;
		}
	}
	int ls=(index/n),hs;
	if (index%n!=0) ls++; 
	if (ls%2) hs=index-((ls-1)*n);
	else hs=n-(index-((ls-1)*n))+1;
	cout<<ls<<' '<<hs<<endl;
	return 0;
}
