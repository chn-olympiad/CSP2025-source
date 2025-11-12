#include<iostream> 
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#define ll long long
using namespace std;
ll a[10]={0};
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll l=s.length();
	for(ll i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']+=1;
	}
	for(ll i=9;i>=0;i--){
		while(a[i]--)cout<<i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
