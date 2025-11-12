#include<bits/stdc++.h>
using namespace std;
int a[1000007],i=1;
char s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s){
		if(s>='0'&&s<='9'){
			a[i]=s-'0';
			i++;
		}
	}
	sort(a+1,a+i+1);
	for(int j=1;j<i;j++){
		cout<<a[i-j+1];
	}
	return 0;
}
