#include<iostream>
using namespace std;
int n,nn[10001];
void baoli(){
	if(n==3){
    int maxn=0,k=0;
    for(int x=1;x<=n;x++){
    	if(nn[x]>maxn)
    	    maxn=nn[x];
    	k+=nn[x];
	}
	if(2*maxn>k)
	    cout<<0;
    else
        cout<<1;}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int x=1;x<=n;x++){
		cin>>nn[x];
	}
    baoli();
	return 0;
}
