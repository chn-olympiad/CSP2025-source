#include<iostream>
#include<cstdio>
#include<string>
int b[1000005]={};
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int la=a.size();
	int lb=0;
	for(int i=0;i<la;i++){
		if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'){
			b[i]=a[i]-'0';
			lb++;
		}
	}
	for(int i=1;i<=lb;i++){
		int max1=0;
		for(int j=0;j<la;j++){
			if(b[j]>=b[max1]){
				max1=j;
			}
		}
		cout<<b[max1];
		b[max1]=0;
	}
	return 0;
}
