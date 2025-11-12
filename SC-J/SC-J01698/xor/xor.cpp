#include<bits/stdc++.h>
using namespace std;
const int N=6e5+5;
int a[N],k,n;
int yihuo(int x,int y){
	if(x==0||y==0) return 1;
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool all_1=true,all_01=true;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1) all_1=false;
		if(a[i]!=1&&a[i]!=0) all_01=false; 
	}
	if(all_1){
		cout<<n/2;
	}else if(all_01){
		if(k==1){
			int c2=0,c1=0;
			bool f[n+5];
			for(int i=0;i<n;i++){
				if(a[i]==0) f[i]=true;
				else{
					f[i]=false;
					c2++;
				}
			}
			for(int i=0;i<n;i++){
				if(f[i]){
					if(i==0){
						if(f[1]){
							f[0]=false;
							f[1]=false;
							c1++;
						}
					}else{
						if(f[i+1]){
							f[i]=false;
							f[i+1]=false;
							c1++;
						}
					}
				}
			}
			cout<<c1+c2;
		}else{
			int c1=0;
			bool f[n+5];
			for(int i=0;i<n;i++){
				if(a[i]==1) f[i]=true;
				else f[i]=false;
			}
			for(int i=0;i<n;i++){
				if(f[i]){
					if(i==0){
						if(f[1]){
							f[1]=false;
							c1++;
						}
					}else{
						if(f[i-1]){
							c1++;
							f[i]=false;
						}else if(f[i+1]){
							c1++;
							f[i+1]=false;
							
						}
					}
				}
			}
			int c2=0;
			for(int i=0;i<n;i++){
				if(f[i]) c2++;
			}
			cout<<c1+c2;
		}
	}else{
		cout<<n;
	}
	return 0;
}