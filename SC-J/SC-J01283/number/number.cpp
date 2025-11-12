#include<bits/stdc++.h>
using namespace std;
#ifdef __unix
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
#define int long long
#define N 1000010
//#define NoFreopen
char s[N];
int num[N],cnt;
signed main(){
	#ifndef NoFreopen
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	#endif
	scanf("%s",s);
	for(int i=0;s[i];++i){
		if(isdigit(s[i])) num[++cnt]=s[i];
	}
	sort(num+1,num+cnt+1,greater<int>());
	for(int i=1;i<=cnt;++i){
		pc(num[i]);
	}
	return 0;
}
