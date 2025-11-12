#include<bits/stdc++.h>
using namespace std;
using ll=long long; 
const int N=1e6+10;
string s,ans="";
int a[11];
int ai;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9') {
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			ans+=i+'0';
		}
	}
	cout<<ans<<endl;
	return 0;
}

