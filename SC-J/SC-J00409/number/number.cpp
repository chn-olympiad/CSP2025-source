#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
string s;
int a[MAXN],t,cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++t]=s[i]-48;
		}
	}
	for(int i=1;i<=t;i++){
		for(int j=i+1;j<=t;j++){
			if(a[i]<a[j]){
				cnt=a[i];
				a[i]=a[j];
				a[j]=cnt;
			}
		}
	}
	for(int i=1;i<=t;i++){
		cout<<a[i];
	}
	return 0;
} 