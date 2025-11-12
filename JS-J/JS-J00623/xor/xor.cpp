#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int mnum=0;
void dfs(int x,int num){
	mnum=max(mnum,num);
	if(x>=n)return ;
	int s=a[x];
	if(a[x]==m)dfs(x+1,num+1);
	for(int i=x+1;i<n;i++){
		s=s^a[i];
		if(s==m)dfs(i+1,num+1);
	}

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		dfs(i,0);
	}
	cout<<mnum;
	return 0;
}
