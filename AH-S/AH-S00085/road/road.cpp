#include<bits/stdc++.h>
using namespace std;
int n,m,k,a,b,c,s1;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++){
		cin>>a>>b>>c;
		s1+=a+b+c;
	}
	c=0;
	for (int i=1;i<=k;i++){
		cin>>a;
		c+=a;
		for (int j=1;j<=m;j++){
			cin>>b;
			c+=b;
		}
		if (c<s1) s1=c;
	}
	cout<<s1;
	
    return 0;
}
