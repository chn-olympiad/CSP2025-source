#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000005],p;
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	p=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[++p]=s[i]-'0';
		}
	}
	sort(num+1,num+1+p);
	for(int i=p;i>=1;i--){
		cout<<num[i];
	}
	return 0;
}