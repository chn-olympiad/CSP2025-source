#include<bits/stdc++.h>
using namespace std;
long long a[1000001];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long l=0,sum=0;
	cin>> s;
	l=s.size();
	for(long long i = 0; i<l; i++){
		if(s[i]>='0' && s[i]<='9'){
			sum++;
			a[sum]=s[i]-'0';
		}
	}
	sort(a+1,a+sum+1);
	for(long long i = sum; i>=1; i--){
		cout<< a[i];
	}
	return 0;
}
