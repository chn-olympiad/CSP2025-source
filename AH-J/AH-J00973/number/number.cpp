#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string s;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size(),cnt=0;
	for(int i=0;i<n;++i){
		if(s[i]>='0'&&s[i]<='9')a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--){
		printf("%d",a[i]);
	}
	return 0;
}
