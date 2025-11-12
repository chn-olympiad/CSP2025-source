#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],len,t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9')a[++t]=(s[i]-'0');
	}
	sort(a+1,a+t+1);
	for(int i=t;i>=1;i--)cout<<a[i];
	cout<<endl;
	return 0;
}
