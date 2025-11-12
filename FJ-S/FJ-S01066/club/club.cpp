#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],c[100010],x,y,z,sum,r,t,n,maxn=0;
void dfs(){
	if(r==n){
		if(maxn<sum){
			maxn=sum;
		}
	}
       for(int i=1;i<=3;i++){
       	if(i==1&&x<=n/2-1){
       		r++;
		   sum+=a[r];
		   x++;
		   dfs();
		   sum-=a[r];
		   r--;
		   x--;
		   }
		   else if(i==2&&y<=n/2-1){
		   	r++;
		   sum+=b[r];
		   y++;
		   dfs();
		   sum-=b[r];
		   r--;
		   y--;
		   }
		   else if(i==3&&z<=n/2-1){
		   	r++;
		   	z++;
		   sum+=c[r];
		   dfs();
		   z--;
		   sum-=c[r];
		   r--;
		   }
	   } 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		maxn=0;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		dfs();
		cout<<maxn<<endl;
	} 
	return 0; 
} 

