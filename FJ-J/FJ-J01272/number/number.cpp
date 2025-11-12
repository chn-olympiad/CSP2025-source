#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int a[1000005];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,j=0,n;
	cin>>s;
	n=strlen(s);
	for(i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j+1]=s[i]-'0';
			j++;
		}
	}
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=j;i++){
		cout<<a[i];
	}
	return 0;
}
