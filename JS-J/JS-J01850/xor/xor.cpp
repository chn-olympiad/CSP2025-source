#include<bits/stdc++.h>
using namespace std;
int a,b,ans=INT_MIN,l,r,z,zz=0;
int c[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	for(int i=1;i<=a;i++){
		if(c[i]==b){
			z=ans;
			zz++;
			if(i>=l&&i<=r){
				ans=max(ans,1);
				zz--;
			}
			if(ans!=z){
				l=i;  r=i;
			}
		}
		int x=c[i];
		for(int j=i+1;j<=a;j++){
			x=x^c[j];
			if(x==b){
				z=ans;
				zz++;
				if(i>=l&&j<=r){
					ans=max(j-i,ans);
					zz--;
				}
				if(ans!=z){
					l=i;  r=j;
				}
			}
		}
	}
	cout<<zz<<endl;
	return 0;
}
