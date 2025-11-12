#include <iostream>
#include <algorithm>
using namespace std;
int a[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int j=1;
	cin>>s;
	for (int i=0;i<s.length();i++){
		if (s[i]>='0' && s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a+1,a+1+j);
	for (int i=j;i>1;i--){
		cout<<a[i];
	}
	
	
	return 0;
}
