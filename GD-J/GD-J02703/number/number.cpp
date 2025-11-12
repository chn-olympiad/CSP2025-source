#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000010],c=1,d;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;a[i]>0;i++){
		if(int(a[i])>=47&&int(a[i]<=57)){
			b[c]=a[i]-48;
			c++;
		}
	}
	for(int i=1;i<c;i++){
		for(int j=1;j<c-i;j++){
			if(b[j]<b[j+1]) {
				swap(b[j],b[j+1]);
			}
		}
	}
	for(int i=1;i<c;i++){
		cout<<b[i];
	}
	return 0;
}
