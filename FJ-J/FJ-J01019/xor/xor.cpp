#include<bits/stdc++.h>
using namespace std;
int n,a[100005],m=1,b,maxn=1;
bool c1[25],c2[25];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>b;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int m=1,n=a[i],s=0;
			for(int l=pow(2,21);l>=1;l/=2){
				if(n>=l){
					n-=l;
					c1[m]=1;
				}else{
					c1[m]=0;
				}
				m++;
			}
			if(i==j){
				for(int k=i;k<=j;k++){
					m=1,n=a[k]+1;
					for(int l=pow(2,21);l>=1;l/=2){
						if(n>=i){
							n-=i;
							c2[m]=1;
						}else{
							c2[m]=0;
						}
						m++;
					}
					for(int l=1;l<=22;l++){
						if(c1[i]!=c2[i]){
							c1[l]=1;
						}else{
							c1[l]=0;
						}
					}
				}
			}else{
				for(int k=i;k<j;k++){
					m=1,n=a[k]+1;
					for(int l=pow(2,21);l>=1;l/=2){
						if(n>=i){
							n-=i;
							c2[m]=1;
						}else{
							c2[m]=0;
						}
						m++;
					}
					for(int l=1;l<=22;l++){
						if(c1[i]!=c2[i]){
							c1[l]=1;
						}else{
							c1[l]=0;
						}
					}
				}
			}
			
			for(int k=pow(2,21);k>=1;k/=2){
				if(c1[k]){
					s+=k;
				}
			}
			if(s=b){
				maxn=max(maxn,j-i+1);
				i=j+1;
				break;
			}
		}
	}
	
	cout<<maxn;
	return 0;
} 
