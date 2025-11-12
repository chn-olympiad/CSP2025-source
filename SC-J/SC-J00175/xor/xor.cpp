#include<bits/stdc++.h> 
using namespace std;
int n,k,b[1009],a,c,l=0,o[100000],o1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		cout<<n;
	}else{
		for(int i=1;i<=n;i++){
			cin>>a;
			c=0;
			int x=1;
			while(1){
				if(a>=x*2){
					x*=2;
				}
			}
			while(a){
				c*=10;
				if(a>=x){
					a-=x;
					c+=1;
				}
				x/=2;
			}
			b[i]=c;
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<n;j++){
				int yy=0;
				for(int i1=i;i1<=j;i++){
					for(int j1=0;j1<o1;j++){
						if(i1==o[j1]){
							yy=1;
							break;
						}
					}
					if(yy){
						break;
					}
				}
				if(yy){
					break;
				}
				if(i==j){
					if(k==0){
						l++;
						break;
					}
				}
				int h[10009];
				for(int r=i;r<=j;r++){
					h[r]=b[r];
				}
				for(int r=i;r<j;r++){
					int u=h[r]+h[r+1],p=0,pp=1;
					while(u){
						if(u%10==1){
							p+=pp;
						}
						pp*=10;
						u/=10;
					}
					h[r+1]=u;
				}
				int u=h[j],p=0,pp=1;
				while(u){
					if(u%10==1){
						p+=pp;
					}
					pp*=2;
					u/=10;
				}
				if(k==pp){
					l++;
					for(int r=i;r<=j;r++){
						o[o1++]=r;
					}
				}
			}
		}
		cout<<l;
	}
}