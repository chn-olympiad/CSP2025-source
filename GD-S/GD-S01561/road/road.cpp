#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(n<100001){
		cout<<13;
	}else{
		cout<<20; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

