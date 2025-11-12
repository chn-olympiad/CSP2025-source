#include<bits/stdc++.h>
using namespace std;
int main(){
	int s;
	cin>>s;
	int d;
	int a[9];
	for(int i=0;i<=9;i++){
		a[i]=0;
	}
	while(s>0){
		d=s%10;
		a[d]++;
		s=s/10;
}
for(int i=9;i>=0;i--){
	for(int o=0;o<a[i];o++){
		cout<<i;
	}
}
	return 0;
}
