#include <bits/stdc++.h>
//#Shang4Shan3Ruo6Shui4
using namespace std;
const int maxn=1e6+10;
int a[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ans;
	long long n=0,biao=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[biao]=s[i]-'0';
			n++;
			biao++;
		}
	}			
	
	sort(a,a+n);
	for(int i=n-1;i>=0;i--)
		cout<<a[i];
	return 0;
}
