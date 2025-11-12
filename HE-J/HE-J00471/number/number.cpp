#include <bits/stdc++.h>
using namespace std;
long long a[1000888];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long sum=0,ans=0;;
	long long n=s.size();
	for(long long i=0;i<n;i++){
		sum++;
		if(s[i]-'0'>=10){
			ans++;
			}else{
				a[i]=s[i]-'0';
		}
	}
	for(long long i=0;i<sum;i++){
		 for(long long j=1;j<sum;j++){
			 if(a[j]>a[j-1]){
				 swap(a[j],a[j-1]);
				 }
			 }
		}
		for(long long i=0;i<sum-ans;i++){
			cout<<a[i];
			}
}
