#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10; 
long long len,a[N],n;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<=len-1;i++){
		if(s[i]>=48&&s[i]<=57){
			n+=1;
			a[n]=s[i]-48;
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 
