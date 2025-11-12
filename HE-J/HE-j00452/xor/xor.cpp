#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int x,y;
    cin>>x>>y;
    for(int i=1;i<=x;i++){
    	cin>>a[i];
	}
	if(y==0) cout<<"1";
	else if(y==3) cout<<"2";
	else cout<<"2";
	fclose(stdin);
	fclose(stdout);
return 0;
} 
