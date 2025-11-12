#include<bits/stdc++.h>
using namespace std;
string a;
int n[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9')
		{
			n[int(a[i])-48]++;
		}
		else continue;
	}
	for(int i=9;i>=0;i--){
		for(int j=n[i];j>0;j--){
			cout<<i;
		} 
	}
	return 0;
} 
