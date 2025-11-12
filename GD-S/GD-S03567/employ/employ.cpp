#include<bits/stdc++.h>
using namespace std;

const int N = 505;
int n,m,p[N];
string s;
bool h = true;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i = 1; i<=n; i++){
		cin>>p[i];
	}
	s = '#'+s;
	for(int i = 1; i<=n; i++){
		if(s[i] == '0') h=false;
	}
	if(h){
		cout<<0<<endl;
		return 0;
	}
	return 0;
} 
