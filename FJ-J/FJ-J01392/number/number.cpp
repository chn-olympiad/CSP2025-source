#include <bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	return a>b;
}
char s[1000007],c[1000007];
int main(){
	freopen("number.in ","r",stdin);
	freopen("number.out","w",stdout);
	int j=0,k=0;
	while (cin>>s[j]){
		if (s[j]>='0'&&s[j]<='9')
			c[k++]=s[j];
		j++;
	}		
	sort(c,c+k,cmp);
	for (int i=0;i<=k;i++) cout<<c[i];
	return 0;
}
