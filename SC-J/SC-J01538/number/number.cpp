#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long int a[N];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long int len=0;
	for(long long int i=0;i<s.size();++i){
		if(s[i]>='0'&&s[i]<='9') a[len++]=s[i]-'0';
	}
	for(long long int j=0;j<len;++j)
		for(long long int i=1;i<=len;++i){
			if(a[i]>=a[i-1]){
				int p=a[i-1];
				a[i-1]=a[i];
				a[i]=p;
			}
		}
	for(long long int i=0;i<len;++i) cout<<a[i];
	return 0;
}