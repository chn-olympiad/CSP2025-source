#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
int a[1000005],j=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=1;i<=s.size();i++){
		if (s[i-1]>='0'&&s[i-1]<='9'){
			a[j]=s[i-1];
			j++;
		}
	}
	sort(a+1,a+j);
	for (int i=j-1;i>=1;i--){
		cout<<a[i]-'0';
	}
}
