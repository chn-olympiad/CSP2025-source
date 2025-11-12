#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[100];
int q,w;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>q>>w;
	for(int i=1;i<=q;i++){
		cin>>a[i];
	}
	cout<<q;
	return 0;
}
