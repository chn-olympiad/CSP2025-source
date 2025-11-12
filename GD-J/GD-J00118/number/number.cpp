#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000001],len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long n=s.size();
	for(long long i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++len]=s[i]-'0';
		}
	}
	sort(a+1,a+len+1);
	if(a[len]==0){
		cout<<0;
		return 0;
	}
	for(long long i=len;i>0;i--){
		cout<<a[i];
	}
	return 0;
}

