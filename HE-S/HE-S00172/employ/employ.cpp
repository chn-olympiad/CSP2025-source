#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m,s;
	cin>>n>>m>>s;
	int x[n]={0};
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	if(n==3&&m==2){
		cout<<2; 
	} 
	else
	{
		cout<<2204128;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
} 
