#include <bits/stdc++.h>
using namespace std;
char a[1000005];
int b[11]={ };
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int t=strlen(a);
	for(int i=0;i<t;i++){
		if(a[i]>='0'&&a[i]<='9'){
			int x=a[i]-'0';
			b[x]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(b[i]--){
			cout<<i;
		}
	}
	return 0;
}
