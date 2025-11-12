#include<bits/stdc++.h>
using namespace std;
unsigned long long s;
int a[10001000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int i=0;
	while(s!=0){
		i++;
		a[i]=s%10;
		s/=10;
	}
	sort(a+1,a+i+1);
	for(int j=i;j>=1;j--){
		cout<<a[j];
	} 
	return 0;
} 
