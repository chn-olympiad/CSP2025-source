#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    cin>>a>>b>>c;
    int d[100005];
    d[0]=a,d[1]=b,d[2]=c;
    sort(d,d+3);
    if(d[2]<d[0]+d[1]){
    	cout<<1;
	}else{
		cout<<0;
	}
    return 0;
}