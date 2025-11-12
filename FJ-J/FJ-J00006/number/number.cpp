#include<bits/stdc++.h>
using namespace std;
//vector<int>a;push_back(1);
//priority_queue<int>a;
long long a[10];
char s[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	long long len=strlen(s);
	for(long long i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
	}
	for(long long i=9;i>=0;i--){
		for(long long j=1;j<=a[i];j++){
			printf("%lld",i);
		}
	}
	return 0;
}
