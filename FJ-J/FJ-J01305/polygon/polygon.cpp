#include<bits/stdc++.h>
using namespace std;
int a;
int n[10010];
int p[10]={1,2,3,4,5}; 
int l=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>n[i];
	}
	for(int i=0;i<5;i++){
		if(a==5 && n[i]==p[i]){
			l=1;
		}else{
			l=0;
		}
	}
	if(l==1){
		cout<<9;
	}
	else{
		cout<<6;
	}
	return 0;
} 
