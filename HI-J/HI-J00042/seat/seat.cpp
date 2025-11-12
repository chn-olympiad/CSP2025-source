#include<bits/stdc++.h>
using namespace std;
const int N=105;
struct Node{
				int r;
				int s;
};
Node a[N];
int n,m;
bool cmp(Node x,Node y){
				return x.s>y.s;
}
int main(){
				freopen("seat.in","r",stdin);
				freopen("seat.out","w",stdout);
				cin>>n>>m;
				for(int i=1;i<=n*m;i++){
								cin>>a[i].s;
				}
				a[1].r=1;
				sort(a+1,a+n*m+1,cmp);
				int idx=0,idy=1;
				for(int i=1;i<=n*m;i++){
								int now_x=0;
								int now_y=0;
								if(idy%2==1){
												now_x=idx+1;
												now_y=idy;
												if(now_x>n){
																now_x--;
																now_y++;
												}
								}
								else{
												now_x=idx-1;
												now_y=idy;
												if(now_x<1){
																now_x++;
																now_y++;
												}
								}
								if(a[i].r){
												cout<<now_y<<' '<<now_x;
												break;
								}
								else{
												idx=now_x;
												idy=now_y;
								}
				}
				return 0;
}
