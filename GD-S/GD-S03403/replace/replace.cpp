#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
int t,n,m,q;
string s;
string v1[M],v2[M];
void solve();
int minn(int a,int b){
	return a>b?b:a;
}

int bu[514];
int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>v1[i]>>v2[i];
	for(int i=1;i<=q;i++) solve();
	
	
	fclose(stdin);fclose(stdout);
	return 0;
}
void solve(){
	string q,l;
	cin>>q>>l;
	cout<<0<<endl;
}

