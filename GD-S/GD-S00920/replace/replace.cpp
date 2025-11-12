#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q;
string s[N][2];
void dfs(string t1,string t2){
	for(int i=1;i<=n;i++){
		
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}string t1,t2;
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		dfs(t1,t2);
	}
	return 0;
}
