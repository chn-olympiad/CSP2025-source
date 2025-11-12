#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int x1,x2,x3;
}a[N];
int n;
bool vis[N];
bool cmp(node p,node q){
	return p.x1>q.x1;
}
int main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	int T;cin>>T;while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x1>>a[i].x2>>a[i].x3;
		}sort(a+1,a+n+1,cmp);long long sum=0;
		for(int i=1;i<=n/2;i++){
			sum+=a[i].x1;
		}cout<<sum;
	}
}