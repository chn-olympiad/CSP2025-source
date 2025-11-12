#include <bits/stdc++.h>
using namespace std;
int num[10];
char number[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>number;
	for(int i=0;i<sizeof(number);i++)
		if(number[i]>='0'&&number[i]<='9')
			num[number[i]-48]+=1;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=num[i];j++)
			cout<<i;
	return 0;
}
