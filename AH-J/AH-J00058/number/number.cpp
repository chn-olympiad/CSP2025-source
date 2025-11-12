#include<bits/stdc++.h>
using namespace std;
int a[1000005],len=0,lenth=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	lenth=s.size();
	for(int i=0;i<lenth;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++len]=s[i]-'0';
		}
	}
	sort(a+1,a+len+1);
	for(int i=len;i>=1;i--)cout<<a[i];
	return 0;
}
