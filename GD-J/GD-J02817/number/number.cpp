#include <bits/stdc++.h>
using namespace std;
string s,sa;
int n,cnt,i,m;
char c;
int a[15];
bool f;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
			if(s[i]>'0') f=1;
		}
	}
	if(f==0){
		cout<<0;
		return 0;
	}
	for(i=9;i>=0;i--){
		while(a[i]){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}

