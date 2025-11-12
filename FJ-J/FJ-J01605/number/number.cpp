#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			n++;a[n]=s[i]-'0';
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[i]<a[j])swap(a[i],a[j]);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i];
	} 
	return 0;
}
