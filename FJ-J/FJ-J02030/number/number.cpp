#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
char a[1000005];
int cmp(char a,char b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	int n=1;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n++]=s[i];
		}
	}
	sort(a+1,a+n,cmp);
	for(int i=1;i<n;i++){
		cout<<a[i];
	}
	return 0;
}
