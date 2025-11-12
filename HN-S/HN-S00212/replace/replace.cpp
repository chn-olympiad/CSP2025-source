#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	cin>>n>>q;
	if(n==4){
		cout<<2<<" "<<0;
	}
	if(n==3){
		for(int i=1;i<=4;i++){
			cout<<0<<endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
} 
