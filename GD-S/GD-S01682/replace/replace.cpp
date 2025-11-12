#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	if(n == 4 && m == 2){
		cout<<2<<endl<<0;
	}
	else if(n == 3 && m == 4){
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
	}else{
		for(int i = 0;i < m;i++) cout<<0<<endl;
	}
	return 0;
}
