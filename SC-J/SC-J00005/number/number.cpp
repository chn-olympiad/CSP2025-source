#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000000+1],k=0;
void so(){
	for(int i=0;i<k;i++){
		for(int j=0;j<k-i;j++){
			if(b[j]<=b[j+1]){
				int p=b[j];
				b[j]=b[j+1];
				b[j+1]=p;
			}
		}
	}
	for(int i=0;i<k;i++){
		cout<<b[i];
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if('0'<=a[i]&&'9'>=a[i]){
			b[k++]=a[i]-48;
		}
	}
	so();
	return 0;
}
