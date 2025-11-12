#include<iostream>
#include<string>
using namespace std;
int b[100000];
int c[100000];
int d[100000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[100000];
	int i=0;
	while(cin>>a[i]){
		i++;
	}
	for(int k=0;k<1000;k++){
		d[k]=-1;
		c[k]=-1;
		b[k]=-1;
	}
	for(int j=0;j<i;j++){
		if(a[j]>47&&a[j]<58){
			b[j]=a[j]-48;
		}
	}
	int ji=0;
	for(int j=0;j<1000;j++){
		if(b[j]!=-1){
			c[ji]=b[j];
			ji++;
		}
	}
	int ji1=0;
	for(int k=0;k<ji;k++){
		int max=0;
		int f=0;
		for(int j=0;j<ji;j++){
			if(c[j]>max&&c[j]!=-1){
				max=c[j];
				f=j;
			}
		}
		c[f]=-1;
		d[ji1]=max;
		ji1++;
	}
	for(int k=0;k<=ji;k++){
		if(d[k]==-1){
			continue;
		}
		cout<<d[k];
	}
	return 0;
} 
