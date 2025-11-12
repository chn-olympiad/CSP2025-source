#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long j=1,sum=s.size();
	for(long long i=0;i<=sum;i++){
		if(s[i]>='0' && s[i]<='9') a[j]=s[i]-48,j++;
	}
	sort(a,a+j);
	for(int i=j-1;i>=1;i--){
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
