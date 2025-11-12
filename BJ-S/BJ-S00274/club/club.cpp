#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll T,n,totx,toty,totz,ans;
struct node{
	ll x,y,z,ch;
}a[100010];
struct Node{
	ll x,id,ch;
}A[100010],B[100010],C[100010],xia[100010];
bool cmp(Node x,Node y){
	return x.x<y.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=totx=toty=totz=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z) A[++totx].x=a[i].x,A[totx].id=i,a[i].ch=1;
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z) B[++toty].x=a[i].y,B[toty].id=i,a[i].ch=2;
			else C[++totz].x=a[i].z,C[totz].id=i,a[i].ch=3;
		}if(totx>n/2){
			for(int i=1;i<=totx;i++){
				if(a[A[i].id].x-a[A[i].id].y<a[A[i].id].x-a[A[i].id].z){
					xia[i].x=a[A[i].id].x-a[A[i].id].y;
					xia[i].ch=2;
					xia[i].id=A[i].id;
				}else{
					xia[i].x=a[A[i].id].x-a[A[i].id].z;
					xia[i].ch=3;
					xia[i].id=A[i].id;
				}
			}sort(xia+1,xia+totx+1,cmp);
			for(int i=1;i<=totx-(n/2);i++){
				a[xia[i].id].ch=xia[i].ch;
			}for(int i=1;i<=n;i++){
				if(a[i].ch==1) ans+=a[i].x;
				if(a[i].ch==2) ans+=a[i].y;
				if(a[i].ch==3) ans+=a[i].z;
			}cout<<ans<<endl;
		}else if(toty>n/2){
			for(int i=1;i<=toty;i++){
				if(a[B[i].id].y-a[B[i].id].x<a[B[i].id].y-a[B[i].id].z){
					xia[i].x=a[B[i].id].y-a[B[i].id].x;
					xia[i].ch=1;
					xia[i].id=B[i].id;
				}else{
					xia[i].x=a[B[i].id].y-a[B[i].id].z;
					xia[i].ch=3;
					xia[i].id=B[i].id;
				}
			}sort(xia+1,xia+toty+1,cmp);
			for(int i=1;i<=toty-(n/2);i++){
				a[xia[i].id].ch=xia[i].ch;
			}for(int i=1;i<=n;i++){
				if(a[i].ch==1) ans+=a[i].x;
				if(a[i].ch==2) ans+=a[i].y;
				if(a[i].ch==3) ans+=a[i].z;
			}cout<<ans<<endl;
		}else if(totz>n/2){
			for(int i=1;i<=totz;i++){
				if(a[C[i].id].z-a[C[i].id].x<a[C[i].id].z-a[C[i].id].y){
					xia[i].x=a[C[i].id].z-a[C[i].id].x;
					xia[i].ch=1;
					xia[i].id=C[i].id;
				}else{
					xia[i].x=a[C[i].id].z-a[C[i].id].y;
					xia[i].ch=2;
					xia[i].id=C[i].id;
				}
			}sort(xia+1,xia+totz+1,cmp);
			for(int i=1;i<=totz-(n/2);i++){
				a[xia[i].id].ch=xia[i].ch;
			}for(int i=1;i<=n;i++){
				if(a[i].ch==1) ans+=a[i].x;
				if(a[i].ch==2) ans+=a[i].y;
				if(a[i].ch==3) ans+=a[i].z;
			}cout<<ans<<endl;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i].ch==1) ans+=a[i].x;
				if(a[i].ch==2) ans+=a[i].y;
				if(a[i].ch==3) ans+=a[i].z;
			}cout<<ans<<endl;
		}
	}
	return 0;
}