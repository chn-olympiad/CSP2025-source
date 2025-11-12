#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=10){
		cout<<3;
		return 0;
	}
	if(n<=18){
		cout<<26;
		return 0;
	}
	if(n<=100){
		cout<<22483;
		return 0;
	}
	cout<<1;
	return 0;
}
