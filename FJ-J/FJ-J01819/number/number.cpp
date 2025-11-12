#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int d[1000005],n=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<strlen(a);i++){
		if(a[i]>='0'&&a[i]<='9'){
			n++;
			d[n]=a[i]-'0';
		}
	}
	sort(d+1,d+n+1);
	for(int i=n;i>=1;i--){
		cout<<d[i];
	}
	return 0;
}
