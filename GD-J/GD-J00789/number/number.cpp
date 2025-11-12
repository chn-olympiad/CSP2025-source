#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000007];
int n,p;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[++p]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=p;i++){
		printf("%d",a[i]);
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
