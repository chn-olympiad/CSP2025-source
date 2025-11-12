#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
long long ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;s[i];i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans++;
			a[ans]=int(s[i]-'0');
		}
	}
	sort(a+1,a+1+ans);
	for(long long i=ans;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 
