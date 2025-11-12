#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000010];
bool cmp(const int &x,const int &y){
	return x>y;
}
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ll cnt=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			a[cnt]=s[i]-'0';
		}	
	}sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	
	return 0;
}
