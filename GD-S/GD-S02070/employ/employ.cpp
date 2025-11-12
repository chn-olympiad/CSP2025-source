#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,m,k,c[N];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') k++;
	}
	if(k<m){
		cout<<0<<endl;
	}
	return 0;
}
