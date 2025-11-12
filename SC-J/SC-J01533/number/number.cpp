#include<bits/stdc++.h>
using namespace std;
int a[1000005];
char b[1000005];
int k=0,c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<1000000;i++){
		cin>>b[i];
		if(b[i]>='0'&&b[i]<='9'){a[k]=b[i]-'0';
			k++;
		}
	}
	sort(a,a+k);
	for(int i=k-1;i>=0;i--)cout<<a[i];
	return 0;
}