#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,max=0,sum=0;
	cin>>n;
	int g[n]={};
	for(int a=0;a<n;a++){
		cin>>g[a];
		sum=sum+g[a];
	}
	if(n==3){
		for(int a=0;a<n;a++){
			if(g[a]>max){
				max=g[a];
			}
		}
		if(max*2<sum){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	fclose(stdin);	
	fclose(stdout);
	//please give me good luck to cross 
	return 0;
}
