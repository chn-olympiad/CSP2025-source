#include<bits/stdc++.h>
using namespace std;
int b[1000001];
int main(){
	freopen("number.in",'w',stdin);
	freopen("number.out",'r',stdout);
	int c=0,i=-1;
	string a;
	cin>>a;
	while(1){
		i++;
		if(a[i]>=48&&a[i]<=122){
			if(a[i]>=48&&a[i]<=57){
				c++;
				b[c]=a[i]-48;
			}
		}else{
			break;
		}
	}
	for(int i=1;i<=c;i++){
		for(int j=1;j<=c-i;j++){
			if(b[j+1]>=b[j]){
				int d=b[j];
				b[j]=b[j+1];
				b[j+1]=d;
			}
		}
	}
	for(int i=1;i<=c;i++){
		cout<<b[i];
	}
	return 0;
}
