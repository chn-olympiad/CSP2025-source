#include<bits/stdc++.h>
using namespace std;
int a[1000];
struct z{
	int num1,num2;
	bool ispublic=0;
}zi[5000];
bool isused[1000]={0};
int xplus,zil;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,l,r;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(l=1;l<=n;l++){
		for(r=l;r<=n;r++){
			xplus=0;
			if(l==r) xplus=a[l];
			else{
				for(int i=l;i<=r;i++){
					xplus=(xplus^a[i]);
				}
			}
			if(xplus==k){
				zi[zil].num1=l;
				zi[zil].num2=r;
				zil++;
			}
		}	
	}
	for(int i=0;i<zil;i++){
		if(!zi[i].ispublic) cout<<zi[i].num1<<" "<<zi[i].num2<<endl;
	}
	cout<<zil;
}
