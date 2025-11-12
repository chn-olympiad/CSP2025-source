#include <iostream>
#include <algorithm>
using namespace std;
string s1;
int const N=1e6+10;
int a[N];
int k;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s1;
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			k++;
			a[k]=s1[i]-'0';
		}
	}
	sort(a+1,a+1+k);
	for(int i=k;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
