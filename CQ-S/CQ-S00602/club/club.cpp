#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n;
struct dy{
	int x,y,z;
}a[100005],b[100005],c[100005]; 
map<dy,int> de;
bool cmp(dy a,dy b){
	return a.x>b.x;
}
int ma=-INT_MAX;
void dfs(int sx,int sy,int sz,int l,int g,int h,int j){
	if(l==n+1){
		ma=max(ma,sx+sy+sz);
		return ;
	} 
	if(g>=(n/2)){
	}else{
		dfs(sx+a[l].x,sy,sz,l+1,g+1,h,j);
	}
	if(h>=(n/2)){
	}else{
		dfs(sx,sy+a[l].y,sz,l+1,g,h+1,j);
	}
	if(j>=(n/2)){
	}else{
		dfs(sx,sy,sz+a[l].z,l+1,g,h,j+1);
	}
	return ;
	
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		de.clear();
		ma=-INT_MAX;
		cin>>n;
		if(n>18){
			int f2=0,f3=0;
			for(int i=1;i<=n;i++){
				cin>>a[i].x>>a[i].y>>a[i].z;
				if(a[i].y==0){
					f2++;
				}
				if(a[i].z==0){
					f3++;
				}
			}
			if(f2==n&&f3==n){
				sort(a+1,a+1+n,cmp);
				int uu=0;
				for(int i=1;i<=n/2;i++){
					uu+=a[i].x;
				}
				cout<<uu<<endl;
				continue;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		dfs(0,0,0,1,0,0,0);
		cout<<ma<<endl;
	}
}
/*
   #####
     #
     #
     #
     #
     #
     #
   #####

  ##    ##
##  #  #  ##
#    ##     #
 #         #
  ##     ##
    ## ##
      #
      
########
#
#
#
#
#
########

########
#
#
#
#
#
########

########
#
#
########
#
#
#
SO let me AC
*/


