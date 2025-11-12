#include<bits/stdc++.h>
using namespace std;
int n,q;
char a;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	stack<string> s;
	cin>>n>>q;
	cin>>a;
	if(!s.empty()&&a!=0){
		cout<<q<<endl<<0;
	}else{
		for(int i=1;i<=n;i++){
			cout<<0;
		}
	}
	return 0;
}
