#include<bits/stdc++.h>
using namespace std;
string s;
long long a[5000001];
long long o;
bool cmp(int a1,int b1){
	return a1>b1;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++o]=s[i]-'0';
		}}
		sort(a+1,a+o+1,cmp);
		for(int i=1;i<=o;i++)cout<<a[i];
	return 0;
	} 
