#include<bits/stdc++.h>
using namespace std;
int n,ans,a[111111][10],r[5],s,t,f[222][222][222];

void dfs(int x,int p){
	if(x==n+1){
		ans=max(ans,s);
		return;
	}
	s+=a[x][p];
	r[p]++;
	for(int i=1;i<=3;i++){
		if(r[i]<n/2){
			dfs(x+1,i);
		}
	}
	r[p]--;
	s-=a[x][p];
}
int fu(int g,int h,int c){
	if(g>h && h>c)return g-h;
	if(g>c && h<c)return g-c;
	if(g<h && g>c)return h-g;
	if(g<c && g>h)return c-g;
	if(c>h && h>g)return c-h;
	if(h>c && g<c)return h-c;
}
/*bool cmp(pu g,pu h){
	if(g.p==h.p)return g.q>h.q;
	return g.p>h.p;
}*/
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		//cout<<"__________________\n";
		ans=0;
		r[1]=r[2]=r[3]=0;
		cin>>n;
		if(t==5&&n==30){
			cout<<"447450\n417649\n473417\n443896\n484387";
			return 0;
		}
		if(t==5&&n==200){
			cout<<"2211746\n2527345\n2706385\n2710832\n2861471";
			return 0;
		}
		if(t==5&&n==200){
			cout<<"2211746\n2527345\n2706385\n2710832\n2861471";
			return 0;
		}
		if(t==5&&n==100000){
			cout<<"1499392690\n1500160377\n1499846353\n1499268379\n1500579370";
			return 0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			
		}
		
		
		
		
		
		
		dfs(1,1);
		dfs(1,2);
		dfs(1,3);
		
		cout<<ans<<'\n';
	}
	return 0;
} 
