#include<bits/stdc++.h>
using namespace std;
char s;
int a[1000001],p=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s){
		if(s>='0'&&'9'>=s){
			a[p++]=s-'0';
		}
	}
	sort(a+1,a+p+1);
	for(int i=p;i>1;i--){
		cout<<a[i];
	}
	return 0;
}

