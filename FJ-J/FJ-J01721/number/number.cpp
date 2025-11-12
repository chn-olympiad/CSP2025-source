#include<bits/stdc++.h>
using namespace std;
char st1[1000010];
int i,num1[11],a,j;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(st1,'a',sizeof(st1));
	memset(num1,0,sizeof(num1));
	cin>>st1;
	for(i=0;i<=1000010;i++){
		a=(int)st1[i];
		if(a>=48 && a<=57)
			num1[a-48]+=1;
	}
	for(i=9;i>=0;i--){
		if(num1[i]!=0)
			for(j=1;j<=num1[i];j++)
				cout<<i;
	}
	return 0;
}
