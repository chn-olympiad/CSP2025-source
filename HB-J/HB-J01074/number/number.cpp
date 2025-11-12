#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],sum=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]<='9' && s[i]>='0'){
			sum++;
			a[sum]=s[i]-'0';
		}
	}
	sort(a+1,a+sum+1);
	for(int i=sum;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}

