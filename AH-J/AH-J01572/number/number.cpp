#include "iostream"
#include "algorithm"
using namespace std;
string s;
int sum=1,a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int  len=s.size();
	for(int i=0;i<len;++i){
		if(s[i]>='0'&&s[i]<='9')a[sum]=s[i]-'0',++sum;
	}
	sort(a+1,a+1+sum);
	for(int j=sum;j>1;--j)printf("%d",a[j]);
	return 0;
}
