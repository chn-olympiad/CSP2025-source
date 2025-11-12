#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,c[507];
string s;
int DFS(int p){
	int a[10000]={0};
	return DFS(p+1);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	DFS(1);
	return 0;
} 
