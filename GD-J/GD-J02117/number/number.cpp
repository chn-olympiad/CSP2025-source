#include <bits/stdc++.h>
using namespace std;
int a[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,ans="";
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
    	if('0'<=s[i]&&s[i]<='9')a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(a[i]--){
			ans+=i+'0';
		}
	}
	cout<<ans;
	return 0;
}

