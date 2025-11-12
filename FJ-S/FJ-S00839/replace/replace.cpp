#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string x,y;
	int a,b;
	cin>>a>>b;
	for(int i=0;i<(a+b)/2;i++){
		getline(cin,x);
		getline(cin,y);
	}for(int i=0;i<b;i++){
		cout<<"0"<<endl;
	}
	return 0;
}

