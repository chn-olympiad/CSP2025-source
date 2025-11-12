#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
string kl;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>kl;
	int n=kl.length();
	for(int i=0;i<n;i++){
		if(kl[i]=='0')a[0]++;
		else if(kl[i]=='1')a[1]++;
		else if(kl[i]=='2')a[2]++;
		else if(kl[i]=='3')a[3]++;
		else if(kl[i]=='4')a[4]++;
		else if(kl[i]=='5')a[5]++;
		else if(kl[i]=='6')a[6]++;
		else if(kl[i]=='7')a[7]++;
		else if(kl[i]=='8')a[8]++;
		else if(kl[i]=='9')a[9]++;
	}
	for(int i=9;i>=0;i--)
		if(a[i]!=0)
			while(a[i]--)printf("%d",i);
	return 0;
} 