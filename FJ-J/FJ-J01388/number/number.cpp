#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool cmp(int a,int b){
	return a>b;
} 
string s;
ll a[1000010],cnt=0,t;
ll ans=0;
int main(){
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	getline(cin,s);
	t=s.size();
	for(int i=0;i<t;i++){
		if(int(s[i])>=48&&int(s[i])<=57){
			a[i]=int(s[i])-48;
			cnt+=1;
		}
	}
	sort(a,a+t,cmp);
	for(int i=0;i<cnt;i++){
		ans=ans*10+a[i];
	}
	printf("%lld",ans);
	return 0;
} 
