#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
string s;
ll a[N],j=1;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a+1,a+j+1,cmp);
	for(ll i=1;i<=j-1;i++)cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
