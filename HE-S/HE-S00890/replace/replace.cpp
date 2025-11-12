#include<bits/stdc++.h>
using namespace std;
const int MXN=2e5+5;
int n,q;
string a[MXN][2],s,t;
int run(){
	int res=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=(int)s.size()-a[i][0].size()-1;j++){
			if(s.substr(j,a[i][0].size())==a[i][0]){
				if(s.substr(0,j)+a[i][1]+s.substr(j+a[i][0].size())==t)res++;
			}
		}
	}
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	while(q--){
		cin>>s>>t;
		s+=' ';
		t+=' ';
		cout<<run()<<endl;
	}
}
