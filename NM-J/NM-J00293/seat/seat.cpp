#include<bits/stdc++.h>
using namespace std;
int n,m,gr[120];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//cin>>n>>m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		//cin>>gr[i];
		scanf("%d",&gr[i]);
	}int rg=gr[1],pm;
	sort(gr+1,gr+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(gr[i]==rg){
			pm=i;
		}
	}int c,r;
	if(pm%n==0){
		c=pm/n;
	}else{
		c=pm/n+1;
	}//'vedone
	if(c%2==0){
		if(pm%n==0){
			r=1;
		}else{
			r=n-(pm%n-1);
		}
	}else{
		if(c==1)
			r=pm;
		else{
			
			if(pm%n==0){
				r=n;
			}else{
				r=(pm%n);
			}
		}
	}
	if(r==0)r++;
	cout<<c<<" "<<r;
	return 0;
}
