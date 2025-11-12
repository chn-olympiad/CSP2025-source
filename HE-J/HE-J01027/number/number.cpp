#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
string s;
int num[MAXN];
long long n=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long l=s.size();
	for(long long i=0;i<=l;i++){
		if (s[i] <= '9' && s[i] >= '0'){
			num[n] = s[i]-48;
			n++;
		}
	}
	sort(num+1,num+n+1);
	for(long long i=n;i>=2;i--){
		cout<<num[i];
	}
	return 0;
}
