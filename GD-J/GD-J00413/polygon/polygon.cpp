#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.ans","w",stdout);
	int m,l,k,j,i,o,p;
	cin>>j;
	int t[j];
	for(i=0;i<j;i++){
		cin>>t[i]; 
	}if(j=3&&t[0]+t[1]>t[2]&&t[2]+t[1]>t[0]&&t[0]+t[2]>t[1]){
		cout<<1;
	}else{
		cout<<j-2;
	}
	return 0;
}
