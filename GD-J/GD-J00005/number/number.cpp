#include <bits/stdc++.h>
using namespace std;
string str;
int len,a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	len=str.size();
	for(int i=0;i<len;i++)
		if(str[i]>='0' and str[i]<='9')
			a[str[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(a[i]!=0){
			cout<<i;
			a[i]--;
		}
	return 0;
}
