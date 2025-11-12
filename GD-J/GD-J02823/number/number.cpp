#include<bits/stdc++.h>
using namespace std;
int a[1000005],tot;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string st;
	cin>>st;
	for(int i=0;i<st.size();++i){
		if('0'<=st[i]&&st[i]<='9') a[++tot]=st[i]-'0';
	}
	sort(a+1,a+tot+1);
	if(a[tot]==0){
		cout<<"0";
		return 0;
	}
	for(int i=tot;i>=1;--i) cout<<a[i];
	return 0;
}
