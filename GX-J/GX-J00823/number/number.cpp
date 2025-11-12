#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s;
	int a[N]={},t=0;
	while(cin>>s){
		if(s>='0' and s<='9'){
			a[t]=s-'0';t++;
		}
	}
	sort(a,a+t);
	for(int i=t-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;	
}
