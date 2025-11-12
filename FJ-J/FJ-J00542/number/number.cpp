#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000001],b[1000001];
	int l=0,k=0;
	for(l=0;l<1000001;l++){
		cin>>a[l];
		if(a[l]=='\0'){
			break;
		}
	}
	for(int i=0;i<l;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[k]=a[i];
			k++;
		}
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			if(b[j]<b[j+1]){
				swap(b[j],b[j+1]);
			}
		}
	}
	cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}