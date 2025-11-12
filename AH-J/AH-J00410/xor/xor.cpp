#include<bits/stdc++.h>
using namespace std;
int a[500000];
long long ans=0,g=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    long long p;
    cin>>n>>k;
    cin>>p;
    a[1]=p;
    for(int i=2;i<=n;i++){
	cin>>a[i];	
	}
	while(g<n){
		for(int i=g+1;i<=n;i++){
		int o=a[i];
		if(o==k){
			g++;
			ans++;
			break;
		}
		bool p=0;
	for(int j=i+1;j<=n;j++){ 
	o^=a[j];
	if(o==k){
		g=j;
	ans++;
	p=1;
	break;		
	}	
	}
	if(p){
		break;
	}
}
	}
	cout<<ans;
    return 0;
}
