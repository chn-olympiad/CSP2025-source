#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000000];
	int b[100000],c=-1e9,l=0,d=0;
	cin>>a;
	long long len=strlen(a);
	for(int i=0;i<=len;i++){
			d=a[i];
			if(d>=48&&d<=57){
			if(d==48){
				b[l]=0;
			}
				if(d==49){
					b[l]=1;
				}
				if(d==50){
					b[l]=2;
				}
				if(d==51){
					b[l]=3;
				}
				if(d==52){
					b[l]=4;
				}
				if(d==53){
					b[l]=5;
				}
				if(d==54){
					b[l]=6;
				}
				if(d==55){
					b[l]=7;
				}
				if(d==56){
					b[l]=8;
				}
				if(d==57){
					b[l]=9;
				}
				l++;
	    }
	}
	for(int i=0;i<=l;i++){
		for(int j=0;j<=l;j++){
			if(b[j]<=b[j+1]){
				swap(b[j],b[j+1]);
			}
	}
    }
	for(int i=0;i<=l-1;i++){
		cout<<b[i];
	}
	return 0;
}
