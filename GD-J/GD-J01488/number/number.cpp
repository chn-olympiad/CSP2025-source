#include<bits/stdc++.h>
using namespace std;
long long a[1000005],j=0;
long long answer=0;
string s;

bool cmp(long long x,long long y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<=s.size();i++){
		if(int(s[i])>=48&&int(s[i])<=57){
			a[j++]=int(s[i])-48;
		}
	}
	sort(0+a,0+a+j,cmp);
	//cout<<j;
	for(long long i=0;i<j;i++){		
		
		answer*=10;
		answer+=a[i];
	}
	printf("%lld\n",answer);
	return 0;
}
