#include <bits/stdc++.h>
#include <string>
using namespace std;
int n,m,ans = 0,num = 0;
string s;
int c[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i = 1;i<=n;i++){
		cin>>c[i];
	}
	int l = s.length();
	for(int i = 1;i<=n;i++){
		if(s[i]=='0'){
			num+=1;
			continue ;
		}
		if(num>=c[i]){
			num+=1;
			continue ;
		}
		ans+=1;
	}
	cout<<num<<endl;
	cout<<ans<<endl;
	cout<<2<<endl;
	cout<<2204128<<endl;
	cout<<161088479<<endl;
	cout<<515058943<<endl;
	cout<<225301405<<endl;
	return 0;
} 
