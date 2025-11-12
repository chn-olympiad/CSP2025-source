#include <bits/stdc++.h>
using namespace std;
char zhou[1000005];
int xiansheng[1000005]={0};
int c=0,i=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> zhou;
	for(i=0;i<=100005;i++)
	{
		if(zhou[i]>=48&&zhou[i]<=57){
		xiansheng[c]=int(zhou[i])-48;
		c++;
		}
	}
	sort(xiansheng,xiansheng+c);
	for(i=c-1;i>=0;i--)
	{
		cout<<xiansheng[i];
	}
	return 0;
}
