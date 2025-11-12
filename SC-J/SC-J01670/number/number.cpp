#include<bits/stdc++.h>
using namespace std;
string s;
int a,b[1000006];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a++;
			b[a]=s[i]-'0';
		}
	}
	sort(b+1,b+1+a);
	for(int i=a;i>=1;i--){
		cout<<b[i];
	}
	return 0;
}