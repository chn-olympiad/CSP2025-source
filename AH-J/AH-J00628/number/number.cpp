#include<bits/stdc++.h>
using namespace std;
int a[10];
int nn=0;
char ch[10000005];
int main(){ 
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>ch[nn]){
		if(ch[nn]=='0')a[0]++;
		else if(ch[nn]=='1')a[1]++;
		else if(ch[nn]=='2')a[2]++;
		else if(ch[nn]=='3')a[3]++;
		else if(ch[nn]=='4')a[4]++;
		else if(ch[nn]=='5')a[5]++;
		else if(ch[nn]=='6')a[6]++;
		else if(ch[nn]=='7')a[7]++;
		else if(ch[nn]=='8')a[8]++;
		else if(ch[nn]=='9')a[9]++;
		nn++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++)cout<<i;
	}
    return 0;
}
