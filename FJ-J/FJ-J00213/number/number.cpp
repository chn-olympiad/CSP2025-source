#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],n,m=0;
bool cmp(int p,int q){
	return p>q;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++m]=s[i]-'0';
		}
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		printf("%lld",a[i]);
	}
	return 0;
}
