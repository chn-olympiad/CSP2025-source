#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int tmp=0,len=s.size();
	for(int i=0;i<len;i++){
		if(int(s[i])>=48&&int(s[i])<=57) a[++tmp]=int(s[i])-48;
	}
	sort(a+1,a+1+tmp);
	for(int i=tmp;i>=1;i--) cout<<a[i];
	cout<<endl;
	return 0;
}
