#include<bits/stdc++.h>
using namespace std;
long long a[1000000+10];
bool cmp(const long long &x,const long long &y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	string s;
	cin>>s;
	long long t=1;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[t]=(s[i]-'0');
			t++;
		}
	}
	sort(a+1,a+t,cmp);
	for(long long i=1;i<t;i++){
		cout<<a[i];
	}
	
	return 0;
} 
