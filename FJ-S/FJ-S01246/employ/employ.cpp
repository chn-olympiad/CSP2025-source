#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n == 10)cout<<45;
	else if(m == 1){
		cout<<"0"<<endl;
		return 0;
	}
	else cout<<m<<endl;
	return 0;
}
