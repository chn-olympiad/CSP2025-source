#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int main()
{
	freopen("number.in","r",FILE);
	freopen("number.out","w",FILE);
	cin>>s;
	int j=1;
	for(int i=0;s[i];i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-48;
			j++;
		}
	}
	j--;
	sort(a+1,a+1+j);
	for(int i=j;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
