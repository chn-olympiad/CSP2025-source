#include <cstdio>
#include <iostream>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	long long b[100005],o=0;
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]<='9'&&a[i]>='0'){
			b[o]=a[i]-'0';
			o++;
		}
	}
	for(int i=0;i<o;i++){
		for(int j=0;j<o-1;j++){
			if(b[j]<b[j+1]){
				swap(b[j],b[j+1]);
			}
		}
	}
	for(int i=0;i<o;i++){
		cout<<b[i];
	}
	return 0;
}
