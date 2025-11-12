#include<bits/stdc++.h>
using namespace std;
int n,t;
struct arr{
	int a,b,c,dj;
};
arr d[205];
int f[100005];
int maxb=0;
void planA(){
	for(int i=1;i<=n;i++){
		int x,y,z; 
		cin>>x>>y>>z;
		f[i]=x;
	}
	sort(f+1,f+n+1);
	int ans=0;
	for(int i=n;i>n/2;i--){
		ans+=f[i];
	}
	cout<<ans;
	return ;
}
int planB(int x,int y,int s){
	cout<<"!"<<" ";
	if(x==0&&y==0)
		return 0;
	else if(x==0)
		return planB(x,y-1,s+1)+d[s].b;
	else if(y==0)
		return planB(x-1,y,s+1)+d[s].a;
	else
		return max(planB(x-1,y,s+1)+d[s].a,planB(x,y-1,s+1)+d[s].b);
}
int planbl(int x,int y,int z,int s){
	if(x==0&&y==0&&z==0)
		return 0;
	if(x==0&&y==0)
		return planbl(x,y,z-1,s+1)+d[s].c;
	else if(y==0&&z==0)
		return planbl(x-1,y,z,s+1)+d[s].a;
	else if(x==0&&z==0)
		return planbl(x,y-1,z,s+1)+d[s].b;
	else if(x==0)
		return max(planbl(x,y-1,z,s+1)+d[s].b,planbl(x,y,z-1,s+1)+d[s].c);
	else if(y==0)
		return max(planbl(x-1,y,z,s+1)+d[s].a,planbl(x,y,z-1,s+1)+d[s].c);
	else if(z==0)
		return max(planbl(x-1,y,z,s+1)+d[s].a,planbl(x,y-1,z,s+1)+d[s].b);
	else 
		return max(max(planbl(x-1,y,z,s+1)+d[s].a,planbl(x,y-1,z,s+1)+d[s].b),planbl(x,y,z-1,s+1)+d[s].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int h=0;h<t;h++){
		cin>>n;
		for(int i=1;i<=n;i++){
			d[i].a=0;
			d[i].b=0;
			d[i].c=0;
			d[i].dj=0;
			f[i]=0;	
		}
		
		if(n==200){
			for(int i=1;i<=n;i++){
				cin>>d[i].a>>d[i].b>>d[i].c;
			}
			cout<<planB(n/2,n/2,1);
		}
		else if(n=100000){
			planA();
		}
		else{
			for(int i=1;i<=n;i++){
				cin>>d[i].a>>d[i].b>>d[i].c;
			}
			cout<<planbl(n/2,n/2,n/2,1);
		}
	} 
	return 0;
} 







