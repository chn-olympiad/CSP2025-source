#include<bits/stdc++.h>
using namespace std;
int n,a[10086],s=0,maxn=0;
int main(){
	freopen("polygon.in","r",stdin);
 	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
 		cin>>a[i];
 		s+=a[i];
 		if(a[i]>maxn){
 			maxn=a[i];
		}
 	}
	if(n>=3&&s>2*maxn){
		cout<<1;
 	}else{ 
		cout<<0; 
	} 
 	return 0;  
} 
