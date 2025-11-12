#include<bits/stdc++.h>
using namespace std;
char c[1000001];
int a[11];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c;
	int len=strlen(c);
	for(int i=0;i<len;i++){
		if(c[i]>='0'&&c[i]<='9') a[c[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
 } 
