#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int n,a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[++n]=s[i]-'0';
		}
	}
	n-=1;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
