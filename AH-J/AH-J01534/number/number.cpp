#include<bits/stdc++.h>
using namespace std;
int b[15];
int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a;
	cin>>a;
	cout<<'q';
	while(a>0){
		b[a%10]++;
		a=a/10;
	}
	for(int i=9;i>=0;i++){
		for(int j=1;j<=b[i];j++){
			cout<<i;
		}
	}
	return 0;
}

