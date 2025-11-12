#include<bits/stdc++.h>
using namespace std;
string s;
long long l,a[1000050],j;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(long long i=0;i<l;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a,a+j);
	for(long long i=j-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 
