#include<bits/stdc++.h>
using namespace std;
const int mn=1e5+1;
int t,n,vis[mn],ax[mn],bx[mn],cx[mn],tot;
struct node{
	int x,y,z;
}e[mn];
int ch(int a,int b,int c){
	if(a==n/2) return 1;
	if(b==n/2) return 2;
	if(c==n/2) return 3;
	return 0;
}
int o(int x,int q){
	int num=0;
	if(x==1){
		for(int i=q;i<=n;i++){
			num+=max(e[i].y,e[i].z);
			}
		return num;
	}
	if(x==2){
		for(int i=q+1;i<=tot;i++){
			num+=max(e[i].x,e[i].z);
			}
		return num;
	}
	if(x==3){
		for(int i=q+1;i<=tot;i++){
			num+=max(e[i].y,e[i].x);
			}
		return num;
	}
	return 0;	
}
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
	    cin>>n;long long num=0,ax,ay,az;
	    for(int i=1;i<=n;i++){
			cin>>e[i].x>>e[i].y>>e[i].z;
		}
		for(int i=1;i<=n;i++){
			if(ch(ax,ay,az)){
				num+=o(ch(ax,ay,az),i);break;
			}
			if(e[i].x>e[i].y and e[i].x>e[i].z){
				ax++;num+=e[i].x;}
			else if(e[i].y>e[i].x and e[i].y>e[i].z){
				ay++;num+=e[i].y;}
			else{
				az++;num+=e[i].z;
			}			
		}
		cout<<num<<endl;
	}
	return 0;
}
