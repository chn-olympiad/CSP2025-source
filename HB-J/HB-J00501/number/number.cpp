#include<bits/stdc++.h>
using namespace std;
string s;
int n,h=0,a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.length();
	for(long long i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[h]=s[i]-'0';
			h++;
		}
	}
	sort(a,a+h+1);
	for(int i=h;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
