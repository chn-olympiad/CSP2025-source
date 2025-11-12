#include<bits/stdc++.h>
using namespace std;
string s;
long long a[200010],sum=0;
bool ac(long long a,long long  b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'a'>=0 && s[i]-'a'<=26) continue;
		if(s[i]-'A'>=0 && s[i]-'A'<=26) continue;
		a[sum]=s[i]-'0';
		sum++;
	}
	sort(a,a+1+sum,ac);
	for(int i=0;i<sum;i++) cout<<a[i];
	return 0;
	fclose(stdin);
	fclose(stdout);
}
