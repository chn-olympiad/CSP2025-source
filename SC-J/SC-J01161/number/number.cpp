#include <bits/stdc++.h>
using namespace std;
const long long N=100000;
string s;
long long  a[N]; 
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
	long long m=s.length();
	for(long long i=0;i<=m-1;i++){
	    if('0'<=s[i]<='9'){             
	    a[s[i]-'0']++;
        }
	}
	for(long long i=9;i>=0;i--){
	    for(long long j=1;j<=a[i];j++){
	    cout<<i;
		}
	}
	return 0;
}