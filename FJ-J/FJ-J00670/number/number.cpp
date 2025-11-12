#include <iostream>
#include <cstring>
using namespace std;

int a[15]= {};
int n=0;

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	for(int i=0; i<str.size(); i++) {
		if(str[i]>='0'&&str[i]<='9') {
			a[str[i]-'0']++;
			n++;
		}
	}
	int i=9;
	while(n>0) {
		if(a[i]>0) {
			a[i]--;
			n--;
			cout<<i;
		} else {
			i--;
		}
	}
	cout<<endl;
	return 0;
}
