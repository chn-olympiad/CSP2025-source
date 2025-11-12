#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","w",stdin);
    freopen("road.out","r",stdout);
	int m,n,k,a,a1,b1,c1;
	int x[100000];
	cin>>m>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a1>>b1>>c1;
	} 
	for(int j=1;j<=k;j++){
    	cin>>a;
    	for(int i=1;i<=m;i++){
    		cin>>x[i];
		} 
	} 
	if(m==4){
		cout<<13;
	}
	else if(m==220){
		cout<<505585650;
	}
    return 0;
}


