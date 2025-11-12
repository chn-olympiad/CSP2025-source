#include<bits/stdc++.h>
using namespace std;
struct az{
	int b,e;
};
bool cmp(az a,az b){
	if(a.e<b.e){
		return true;
	}else if(a.e==b.e){
		return a.b<=b.e;
	}
	return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k1,z=0,z1=1;
	cin>>n>>k1;
	az c[100000]={};
	int a[n+1]={},k[n+1]={};
	for(int i=1;i<=n;i++){//无误 
		cin>>a[i];
		if(i!=1){
			k[i]=a[i]^k[i-1];
		}else{
			k[i]=a[i];
		}
	}
	k[0]=a[1]; 
	
	for(int i=1;i<=n;i++){//无误 
		for(int j=i;j<=n;j++){
			if(i==j && a[i]==k1){
				c[z].b=i;
				c[z++].e=j;
			}else{
				if(i==1 && k[j]==k1){
					c[z].b=i;
					c[z++].e=j;
					continue;
				}
				if(i!=j && int(k[j]^k[i-1])==k1){
					c[z].b=i;
					c[z++].e=j;
				}
			}
		}
	}
	sort(c,c+z,cmp);
	for(int i=1;i<z;i++){
		if(c[i].b>=c[i-1].e){
			z1++;
		}
	}
	cout<<z1;
	return 0;
}
