#include<bits/stdc++.h>
#define int long long
using namespace std;

string s;
char a[1000100];
int ans=0;
int len,sz=0;
bool cmp(char xx,char yy){
	return xx>yy;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if('0'<=s[i] && s[i]<='9'){
			a[++sz]=s[i];
		}
	}
	sort(a+1,a+sz+1,cmp);
	for(int i=1;i<=sz;i++){
		cout<<a[i];
	}
	return 0;
}
