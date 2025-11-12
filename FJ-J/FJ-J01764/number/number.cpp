#include<bits/stdc++.h>
using namespace std;
string s;
long long n,a[1000005],j=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-48;
			j++;
		}
	}
	sort(a+1,a+1+j);
	for(int i=j;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 
