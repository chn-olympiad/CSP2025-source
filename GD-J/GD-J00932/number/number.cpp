#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll ans,a[1100000],t1=1;
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[t1++]=s[i]-48;
		}
	}
	sort(a+1,a+t1);
	for(int i=t1-1;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 
