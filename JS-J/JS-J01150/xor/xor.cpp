#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200005];
bool vis[200005];
int n,k;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f=0;
for(int i=0;i<n;i++){
	cin>>a[i];
	if(i>0&&a[i]!=a[i-1])f=1;
}
if(f==0&&k==0){//10pts 0 qie xiang tong
	cout<<n/2;
}
	return 0;
}
//xiangtong ze 0
//butong ze 1
//ji shu ge 1/0 xiang ^ =1
//ou shu ge 1/0 xiang ^ =0
// 0 1 1 0 0 1 1 1
// * - - * * - - + 5
// 0 1 0 1 0 1 0 1 
