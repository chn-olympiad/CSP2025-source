#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long sl=s.length();
	long long sum=1;
	for(int i=0;i<sl;i++){
		if(s[i]-'0'<=9&&s[i]-'0'>=0) a[sum]=s[i]-'0',sum++;
	}
	sort(a+1,a+sum+1);
	for(int i=sum;i>1;i--) cout<<a[i];
	return 0;
}
