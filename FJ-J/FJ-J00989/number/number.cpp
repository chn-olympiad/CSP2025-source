#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long a[10];
	for(long long i=0;i<10;i++) a[i]=0;
	for(long long i=0;i<s.size();i++){
		long long c=s[i];
		if(c>=48&&c<=57){
			if(c==48) a[0]++;
			else if(c==49) a[1]++;
			else if(c==50) a[2]++;
			else if(c==51) a[3]++;
			else if(c==52) a[4]++;
			else if(c==53) a[5]++;
			else if(c==54) a[6]++;
			else if(c==55) a[7]++;
			else if(c==56) a[8]++;
			else if(c==57) a[9]++;
		}
	}
	for(long long i=9;i>=0;i--){
		for(long long j=0;j<a[i];j++){
			cout<<i;
		}
	}
	return 0;
}
