#include<bits/stdc++.h>
using namespace std;
//It isn't true code.
long long n,k,a[(long long)5e5],s,num;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		num^=a[i];
		if(num==k){
			s++;
			num=0;
		}
	}
	cout<<s;
	return 0;
}
