#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a[100001];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0' && s[i]<='9')
			a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(a[i]--)
			printf("%d",i);
	}
	return 0;
}
