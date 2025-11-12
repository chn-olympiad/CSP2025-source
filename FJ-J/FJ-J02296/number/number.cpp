#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long h=1;
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>=48&&s[i]<=57){
			a[h]=s[i]-48;
			h++;
		}
	}
	sort(a+1,a+h);
	for(int l=h-1;l>0;l--){
		cout<<a[l];
	}
	return 0;
} 
