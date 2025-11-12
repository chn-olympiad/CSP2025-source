#include<bits/stdc++.h>
using namespace std;
string st;
int num[1000010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,st);
	int tot=0;
	for(int i=0;i<st.length();i++){
		if(st[i]>'9'||st[i]<'0') continue;
		num[++tot]=(st[i]-'0');
	}
	sort(num+1,num+1+tot);
	for(int i=tot;i>=1;i--){
		cout<<num[i];
	}
	return 0;
}
