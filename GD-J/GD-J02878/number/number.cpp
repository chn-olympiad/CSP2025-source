#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int w=1;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<=9+'0'){
			a[w]=s[i]-'0';
			w++;
		}
	}
	sort(a+1,a+w);
	for(int i=w-1;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
