#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int n;
char a[MAXN];
long long cnt[MAXN];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a+1);
	n=strlen(a+1);
	for(int i=1;i<=n;i++){
		if('0'<=a[i]&&a[i]<='9'){
			cnt[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++){
			cout<<i;
		}
	}
	return 0;
}