#include <bits/stdc++.h>
using namespace std;
int a[1000005];
char s[1000005];
bool cmp (int a,int b){
	return a>b;
	}
int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int l=1;
    cin>>s;
    int len=strlen(s);
    for (int i=0;i<len;++i){
		if (s[i]-'0'>=0&&s[i]-'0'<=9)
		a[l++]=s[i]-'0';
	}
	l--;
	sort(a+1,a+1+l,cmp);
	for (int i=1;i<=l;i++){
		printf("%d",a[i]);
		}
	cout<<endl;
	return 0;
	}
