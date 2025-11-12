#include<bits/stdc++.h>
using namespace std;
string x;
int a[10]; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x;
	for(int i=0;i<x.size();i++){
		if(x[i]<='9'&&x[i]>='0')
		a[x[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	for(int t=1;t<=a[i];t++)
	printf("%d",i);
	
	
	return 0;
}
