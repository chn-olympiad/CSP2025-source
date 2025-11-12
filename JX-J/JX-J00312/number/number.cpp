#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
string s;
int a[1005];
int n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			n++;
			a[i]+=s[i]-'0';
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++) cout<<a[i];
	return 0;
}
