#include<bits/stdc++.h>
using namespace std;
struct my{
	int a1,a2,a3;
}a[100005];
long long mx;
void dfs(int n,int i,int d1,int d2,int d3,long long num){
	if(i==n){
		mx=max(num,mx);
		return;
	}
	if(d1<(n/2))dfs(n,i+1,d1+1,d2,d3,num+a[i].a1);
	if(d2<(n/2))dfs(n,i+1,d1,d2+1,d3,num+a[i].a2);
	if(d3<(n/2))dfs(n,i+1,d1,d2,d3+1,num+a[i].a3);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		mx=INT_MIN;
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		dfs(n,0,0,0,0,0);
		cout<<mx<<endl;
	}
	return 0;
}
