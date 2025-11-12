#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long a[1000001]={};
	long long f=0;
	long long l=s.length();
	for(long long i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
				a[f]=s[i]-'0';
				f++;
			}
		}
		sort(a,a+f);
		for(long long i=f-1;i>=0;i--){
			cout<<a[i];
		}
	return 0;
	}
