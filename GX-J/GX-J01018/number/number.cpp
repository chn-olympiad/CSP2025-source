#include<bits/stdc++.h>
using namespace std;
int l[10000000]={};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long a,b=1,d=1;
	cin>>a;
	long c=a;
	while(c!=0){
		if(c/10!=0){
			c=c/10;
			b++;
		}
		else c=0;
	}
	for(int i=1;i<=b;i++){
		l[i]=a/d%10;
		d*=10;
	}
	sort(l+1,l+b+1,cmp);
	for(int i=1;i<=b;i++)cout<<l[i];
}
