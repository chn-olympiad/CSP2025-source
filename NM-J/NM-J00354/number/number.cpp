#include <iostream>
#include <string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char a[1000000] = {};
	cin>>s;
	int n = 0;
	for(int i = 0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i];
			n++;
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			int z=j;
			z++;
			if(a[j]<a[z]){
				int t = a[j];
				a[j]=a[z];
				a[z]=t;
			}
		}
	}
	cout<<a;
	return 0;
}
//123
//132
//213
//231
//312
//321

//1234
//1243
//1324
//1342
//1423
//1432
//.....
