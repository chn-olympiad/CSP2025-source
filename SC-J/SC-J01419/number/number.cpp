#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000010];
bool cmp(ll a,ll b){
	return a>b;
} 
int main(){
	string s;
	int sum=0,cnt;
	freopen("number.in","r",s);
	ll len=s.size(),l=1;
	for(ll i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[l]=s[i]-'0';
			l++;
		}
	}
	sort(a+1,a+l,cmp);
	for(ll i=1;i<l;i++){
		sum=sum*10+a[i];
	}
	freopen("number.out","w",sum);
	return 0;
} 