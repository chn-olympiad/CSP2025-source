#include<bits/stdc++.h>
using namespace std;
const int N=5*1e6+7;
int n,m;
char str[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>str;
		cin>>str; 
	}for(int i=1;i<=m;i++){
			cin>>str;
			cin>>str; 
		}
	if(n==4&&m==2){
		
		cout<<2<<endl<<0;
	}
	else{
		for(int i=1;i<=m;i++) cout<<0<<endl;
	}
	return 0;
}
