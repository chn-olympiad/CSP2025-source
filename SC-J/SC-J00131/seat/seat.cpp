#include<bits/stdc++.h>
#define LL long long
#define rep(i,k,n) for(LL i=k;i<=n;i++)
#define VI vector<int>
using namespace std;
bool cmp(int a,int b){
	return a>b;}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	VI a(n*m+1);
	rep(i,1,n*m)cin>>a[i];
	int R=a[1];
	sort(a.begin()+1,a.end(),cmp);
	int i=1,j=1;
	rep(p,1,n*m){
		if(a[p]!=R){
			if(j%2==1&&i!=n)i++;
			else if(j%2==0&&i!=1)i--;
			else if(j%2==1&&i==n)j++;
			else if(j%2==0&&i==1)j++;}
		else break;}
	cout<<j<<' '<<i;}