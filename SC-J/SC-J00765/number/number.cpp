#include<bits/stdc++.h>
using namespace std;
string s;
long long a[9000005],t;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++t]=s[i]-'0';
		}
	} 
	sort(a+1,a+1+t,cmp);
	for(int i=1;i<=t;i++)cout<<a[i];
	return 0;
}
