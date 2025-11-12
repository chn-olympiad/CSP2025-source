#include<bits/stdc++.h>
using namespace std;
char a[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int n=strlen(a);
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		if(a[i]>='0'&&a[i]<='9'){
			cout<<a[i];
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
