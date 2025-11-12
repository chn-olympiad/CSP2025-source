#include<bits/stdc++.h>
using namespace std;
char a[10000000+10];
int m[10000000+10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int p=0;
	cin>>a;
	for(int i=0; i<=strlen(a); i++){
		if(a[i]>='0'&&a[i]<='9'){
			p++;
			m[p]=(a[i]-'0');
		}
	}
	sort(m+1,m+p+1);
	for(int i=p; i>=1; i--){
		cout<<m[i];
	}
	return 0;
}
