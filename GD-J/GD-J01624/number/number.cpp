#include<bits/stdc++.h>
using namespace std;
string s;
int a[1005];
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	int t=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[1]<='9'){
			a[t++]=s[i];
		}
	}
	sort(a+t+1,a+1);
	for(int i=1;i<=t;i++){
		cout<<a[i];
	}
	return 0;
}
