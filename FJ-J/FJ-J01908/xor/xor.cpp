#include<bits/stdc++.h>
using namespace std;

int n,k,ans;
int a[500010];

int xor_(int x,int y){
	int z=0,k=1;
	if(x<y) swap(x,y);
	while(y!=0){
		if(!(x%2 == y%2))
			z+=k;
		k*=2;x/=2;y/=2;
	}z+=x*k;
	return z;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int s=xor_(a[i],a[j]);
			if(i==j){if(a[i]==k){i=j;ans++;break;}}
			else if(s==k){i=j;ans++;break;}
			else a[i]=s;
		}
	}	
	cout<<ans;	
	return 0;
} 
