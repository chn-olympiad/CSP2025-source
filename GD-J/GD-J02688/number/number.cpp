#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5;
string s;
int a[M],cnt=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0; i<s.size(); i++){
		if ((s[i]-'0')>=0&&(s[i]-'0')<=9) a[cnt]=(int)(s[i]-'0'),cnt++;
	}cnt--;
	sort(a+1,a+cnt+1);
	for (int i=cnt; i>=1; i--) cout<<a[i];
	return 0;
}
