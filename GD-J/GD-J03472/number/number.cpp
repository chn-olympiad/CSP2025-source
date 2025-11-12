#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char a[N];
char s[N];
int n; 
int main(){
//	freopen("number1.in","r",stdin);
//	freopen("number1.out","w",stdout);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;a[i];i++){
		if(a[i]>='0'&&a[i]<='9') s[++n]=a[i];	
	}
	sort(s+1,s+1+n,greater<char>());
	for(int i=1;i<=n;i++) cout<<s[i];
	return 0;
}

