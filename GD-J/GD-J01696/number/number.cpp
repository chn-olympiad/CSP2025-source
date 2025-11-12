#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
string s;
long long a[N],b,n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[b++]=s[i]-'0';
			n++;
		}
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
			cout<<a[i];
	}
	cout<<endl;
	return 0;
} 
