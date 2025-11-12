#include<iostream>
#include<algorithm>
using namespace std;
string a;
int num[1000005],len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0' and a[i]<='9')num[++len]=a[i]-'0';
	}
	sort(num+1,num+len+1);
	for(int i=len;i>=1;i--)cout<<num[i];
	return 0;
}
