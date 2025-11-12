#include<bits/stdc++.h>
using namespace std;
string s;
long long len,a[15]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(long long i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9') a[(int)(s[i]-'0')]++;
	}
	for(long long i=9;i>=0;i--){
		for(long long j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}