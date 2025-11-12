#include<bits/stdc++.h>
using namespace std;
bool cnt(int x,int y){
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
 char a[1000007];
cin>>a;
int len=strlen(a);
int sum=1;
int k[len+5];
for(int i=0;i<len;i++){
	if(a[i]>='0' and a[i]<='9'){
		k[sum]=(int)a[i]-48;
		sum++;
		
	}
}
sort(k+1,k+sum,cnt);
for(int i=1;i<sum;i++){
	cout<<k[i];
}
fclose(stdin);
fclose(stdout);

     return 0;
}

