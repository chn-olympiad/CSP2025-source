#include<iostream>
#include<algorithm>
using namespace std;
string x;
int a[1000005];
int j=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>x;
	for(int i=0;i<x.size();i++){
		if('0'<=x[i]&&x[i]<='9'){
			a[++j]=x[i]-'0';
		}
	}
	sort(a+1,a+j+1);
	for(int i=j;i>0;i--){
		cout<<a[i];
	}
} 
