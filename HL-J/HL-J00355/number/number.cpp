#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int a[10000005],sum;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[sum]=s[i]-48;
			sum++;
		}
	}
	sort(a,a+sum,cmp);
	for(int i=0;i<sum;i++){
		cout<<a[i];
	}
	return 0;
}