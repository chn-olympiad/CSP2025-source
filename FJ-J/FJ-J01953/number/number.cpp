#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char a[2000005];
int b[2000005];
bool k(int m,int n){
	return m>n;
}
int main(){
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	cin>>a;
	int l=1;
	for(int i=0;i<strlen(a);i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[l]=int(a[i])-48;
			l++;
		}
	}
	sort(b+1,b+l,k);
	for(int i=1;i<l;i++){
		cout<<b[i];
	}
	return 0;
} 
