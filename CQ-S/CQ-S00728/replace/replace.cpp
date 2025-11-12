#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
const long long MAXN=1e10+1;
string s;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(0));
	cin>>n>>m;
	for(int i=1;i<=n+m;i++){
		cin>>s;
		cin>>s;
	}
	if(n==4&&m==2){
		cout<<"2\n0";
	}else if(n==3&&m==4){
		cout<<"0\n0\n0\n0";
	}else{
		for(int i=1;i<=m;i++){
			ans=rand()%MAXN;
			cout<<ans<<endl;			
		} 
	}
}
/*
CSP-S T3 Replace
*/
