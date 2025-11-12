#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    char a[1000001]={0};
    cin>>a;
    int sum0=0,sum1=0,sum2=0,sum3=0,sum4=0,sum5=0,sum6=0,sum7=0,sum8=0,sum9=0;
    for(int i=0;i<1000001;i++){
		if(a[i]=='0')sum0++;
		if(a[i]=='1')sum1++;
		if(a[i]=='2')sum2++;
		if(a[i]=='3')sum3++;
		if(a[i]=='4')sum4++;
		if(a[i]=='5')sum5++;
		if(a[i]=='6')sum6++;
		if(a[i]=='7')sum7++;
		if(a[i]=='8')sum8++;
		if(a[i]=='9')sum9++;
	}
    for(int i=1;i<=sum9;i++)cout<<9;
	for(int i=1;i<=sum8;i++)cout<<8;
	for(int i=1;i<=sum7;i++)cout<<7;
	for(int i=1;i<=sum6;i++)cout<<6;
	for(int i=1;i<=sum5;i++)cout<<5;
	for(int i=1;i<=sum4;i++)cout<<4;
	for(int i=1;i<=sum3;i++)cout<<3;
	for(int i=1;i<=sum2;i++)cout<<2;
	for(int i=1;i<=sum1;i++)cout<<1;
	for(int i=1;i<=sum0;i++)cout<<0;
    return 0;
}
