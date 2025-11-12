#include <bits/stdc++.h>

using namespace std;
char a[1000000+5000];
int n[10],k=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	while (a[k]!='\0'){
		if (a[k]>='0' && a[k]<='9'){
			n[a[k]-'0']++;
		}
		k++;
	}
	for (int i=9; i>=0;){
		if (n[i]==0) i--;
		else{
			cout<<i;
			n[i]--;
		}
	}
	return 0;
}
