#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
string s;
ll a[1000010]={0};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll j=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9' ){
			a[j]=s[i]-48;
			j++;
		}
	}
	
	sort(a,a+j,cmp);
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
	
	
	
	return 0;
}