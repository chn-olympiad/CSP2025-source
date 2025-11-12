#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int b[1000005];
int sj=0;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		char a=s[i];
		if(a>='0'&&a<='9'){
			b[++sj]=a;
			b[sj]-=48;
		}
	}
	sort(b+1,b+sj+1);
	for(int i=sj;i>=1;i--){
		cout<<b[i];
	}
	return 0;
} 
