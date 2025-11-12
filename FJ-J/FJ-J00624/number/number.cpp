#include<bits/stdc++.h>
using namespace std;
string str;
long long a[1000010],cnt;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(long long i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9'){
			a[++cnt]=str[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(long long i=1;i<=cnt;i++){
		printf("%lld",a[i]);
	}
	return 0;
}
