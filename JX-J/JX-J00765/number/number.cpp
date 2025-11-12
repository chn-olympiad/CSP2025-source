#include<bits/stdc++.h>
using namespace std;
string s;
long long n[1000500]={0},c=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long m=s.size();
	for(long long i=0;i<m;i++){
		for(long long j=0;j<9;j++){
			if(s[i]==char('0'+j)){
				n[i]=j;
				c++;
			}
		}
	}
	sort(n,n+c);
	for(long long i=c-1;i>=0;i--){
		cout<<n[i];
	}
	return 0;
}
