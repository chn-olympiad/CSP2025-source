#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000000]={','};
	int d[10000],c=0,len;
	cin>>a[1000000];
	for(int i=0;i<1000000;i++){
		if(a[i]!=','){
			len++;
		}
	}
	for(int i=0;i<len;i++){
		if (a[i]>='0'&&a[i]<='9'){
			c++;
		}
	}
	for(int i=0;i<c;i++){
		for(int j=0;j<len;j++){
			if(a[j]>='0'&&a[j]<='9'){
				d[i]=a[j];
				i++;
			}
		}
	}
	for(int i=0;i<c-1;i++){
		if(d[i]<d[i+1]){
			swap(d[i],d[i+1]);
		}
	}
	cout<<d;
	return 0;
}
