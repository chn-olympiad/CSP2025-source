#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int,int>
#define ull unsigned long long
const int N=1e5+10;
struct node{
	int va,id;
}p[N];
bool cmp(node a,node b){
	return a.va>b.va;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int tot=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>p[++tot].va;
			p[tot].id=0;
		}
	}
	p[1].id=1;
	sort(p+1,p+1+tot,cmp);
	int k;
	for(int i=1;i<=tot;i++){
		if(p[i].id==1){
			k=i;
			break;
		}
	}
	cout<<((k-1)/n)+1<<" ";
	if(((k-1)/n+1)%2==1){
		cout<<(k-1)%n+1;
	}
	else cout<<n-((k-1)%n);
	return 0;
}