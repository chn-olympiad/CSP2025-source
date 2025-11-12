#include<bits/stdc++.h>
using namespace std;
char s[1000005];
long long a[1000005],i=1,j;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>s[i]){
		i++;
	}
	for(long long k=1;k<=i;k++){
		if('0'<=s[k]&&s[k]<='9'){
			j++;
			a[j]=s[k]-'0';
		}
	}
	sort(a+1,a+j+1,cmp);
	for(long long k=1;k<=j;k++){
		printf("%lld",a[k]);
	}
	return 0;
}

