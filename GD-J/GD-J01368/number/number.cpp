#include<bits/stdc++.h>
using namespace std;
long long a[25],bj;
string st;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	for(int i=0;i<st.size();i++) 
		if(st[i]<='9'&&st[i]>='0') a[st[i]-'0']++;
	for(int i=9;i>=1;i--)
		for(int j=a[i];j>=1;j--) cout<<i,bj=1;
	if(!bj) {
		if(a[0]) cout<<0;
		return 0;
	}
	for(int i=a[0];i>=1;i--) cout<<0;
	return 0;
}

