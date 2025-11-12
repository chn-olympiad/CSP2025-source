#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6+10;
int a[N],sum=0;string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++)
		if(s[i]>='0'&&s[i]<='9'){
			sum++;
			a[sum]=s[i]-'0';
		}	
	sort(a+1,a+1+sum);
	for(int i=sum;i>=1;i--) printf("%d",a[i]);
	return 0;
}