#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int n,cnt[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=strlen(s);
	for(int i=0;i<n;++i)
		if(s[i]>='0'&&s[i]<='9')
			++cnt[s[i]-'0'];
	for(int i=1;i<=cnt[9];++i)
		printf("9");
	for(int i=1;i<=cnt[8];++i)
		printf("8");
	for(int i=1;i<=cnt[7];++i)
		printf("7");
	for(int i=1;i<=cnt[6];++i)
		printf("6");
	for(int i=1;i<=cnt[5];++i)
		printf("5");
	for(int i=1;i<=cnt[4];++i)
		printf("4");
	for(int i=1;i<=cnt[3];++i)
		printf("3");
	for(int i=1;i<=cnt[2];++i)
		printf("2");
	for(int i=1;i<=cnt[1];++i)
		printf("1");
	for(int i=1;i<=cnt[0];++i)
		printf("0");
	return 0;
}
