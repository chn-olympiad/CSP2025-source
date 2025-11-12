#include<bits/stdc++.h>
using namespace std;
string s;
long long a[5000005],sum=0;
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>=0&&s[i]<=9){
			sum++;
			a[sum]=s[i];
		}
	}
sort(a,a+sum);
for(int i=1;i<=sum;i++){
	cout<<a[i];
}
	return 0;
}