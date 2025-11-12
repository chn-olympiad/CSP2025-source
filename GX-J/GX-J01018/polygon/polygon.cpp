#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int l[10000000]={};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long a,c=0;
	cin>>a;	
	for(int i=1;i<=a;i++){
		cin>>l[i];
	}
	if(l[1]+l[2]+l[3]>2*l[3])c++;
	cout<<c;
}
