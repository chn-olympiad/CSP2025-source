#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N],cnt=0;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	freopen("number3.in","r",stdin);
	//freopen("number2.ans","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			cnt++;
			a[cnt]=s[i]-'0';
		}
	//	cout<<s[i]-'0'<<' ';
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--)cout<<a[i];
	cout<<'\n';
	return 0;
}
