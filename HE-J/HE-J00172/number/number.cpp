#include<bits/stdc++.h>
using namespace std;
long long x[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long j=1;
	for(long long i=0;i<s.size();i++){
		long long a=s[i]-'0';
		if(a>=0&&a<=9){
			x[j]=a;
			j++;
		}
	}
	sort(x+1,x+j);
	for(long long i=j-1;i>=1;i--){
		cout<<x[i];
	}
	return 0;
}
