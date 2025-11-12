#include <bits/stdc++.h>
using namespace std;
long long a[10];
string ans="";
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long len=s.size();
	for(long long i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int k=s[i]-'0';
			a[k]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			char t=i+'0';
			ans+=t;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
