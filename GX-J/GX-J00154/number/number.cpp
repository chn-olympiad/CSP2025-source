#include<iostream>
using namespace std;
char s;
long a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s){
		if ('0'<=s && '9'>=s)a[s-'0']++;
	}
	for (int i=9;i>=0;i--){
		while(a[i]--)cout<<i;
	}
	return 0;
}
