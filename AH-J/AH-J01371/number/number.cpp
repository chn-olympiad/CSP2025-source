#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005],j=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
		j++;
		}
	}
	sort(a+0,a+j);
	for(int i=j-1;i>=0;i--)
		printf("%d",a[i]);
return 0;
}
