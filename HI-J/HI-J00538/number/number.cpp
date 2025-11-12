#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	char b[1000005];
	int x=0;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if (a[i]>=48 && a[i]<=57){
			b[x]=a[i];
			x++;
		}
	}
	sort(b,b+x);
	x-=1;
	for(int i=x;i>=0;i--){
		cout<<b[i];
	}
	return 0;
} 
