#include <bits/stdc++.h>
using namespace std;
char a[1000005];
char n[1000005];
int sum=0;
bool cmp(char q,char p){
	return q>p;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int s=strlen(a);
	for(int i=0;i<s;i++){
		if(a[i]>='0'&&a[i]<='9'){
			sum++;
			n[sum]=a[i];
		}
	}
	sort(n+1,n+1+sum,cmp);
	for(int i=1;i<=sum;i++) cout<<n[i];
	return 0;
}
//100pts
