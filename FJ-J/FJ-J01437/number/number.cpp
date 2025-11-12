#include <iostream>
#include <algorithm>
using namespace std;
string s;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int sum=0;
	for (int i=0; i<s.size(); i++){
		if (s[i]>='0' && s[i]<='9'){
			sum++;
			a[sum]=(int)(s[i]-'0');
		}
	}
	sort(a+1,a+sum+1);
	for (int i=sum; i>=1; i--){
		cout<<a[i];
	}
	return 0;
}
