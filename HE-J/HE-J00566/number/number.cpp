#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	char s[];
	cin>>s[];
	int a[side(s)];
	int b=0;
	int x;
	for(int i=0;i<=side(s);i++){

		if(s[i]>='z'){

			a[b]=s[i];
			b+=1;
		}
	}
	for(int i=0;i<=b;i++){
		for(int j=b;j>=0;j--){
			if(a[j]>a[j-1]){
				x=a[j-1];
				a[j-1]=a[j];
				a[j]=x;

			}
		}
	}
	for(int i=0;i<=b;i++){
		cout<<a[i];
	}


	fclose("stdin");
	fclose('stdout');
		return 0;




}
