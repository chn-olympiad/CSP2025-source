#include<bits/stdc++.h>
using namespace std;
long long a[12345678];
long long b[12345678];
string s;
long long n;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i]-'0';
			n++;
		}
	}
	
	sort(a,a+n,cmp);
	
	for(int i=0;i<n;i++){
		cout<<a[i];
	}

	return 0;
}

