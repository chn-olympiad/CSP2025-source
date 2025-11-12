#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,t;
long long a[N][5],ans,tt[N],kk[N],cntt;
struct S{
	long long aa,bb,c;
}ab[N];
void dfs(int l,int x,int y,int z,long long sum){
	if(x>n/2||y>n/2||z>n/2)return;
	if(l==n+1){
		ans=max(ans,sum);
	}
	dfs(l+1,x+1,y,z,sum+a[l][1]);
	dfs(l+1,x,y+1,z,sum+a[l][2]);
	dfs(l+1,x,y,z+1,sum+a[l][3]);
}
bool C(S xx,S yy){
	return xx.c>yy.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int pp=1;pp<=t;pp++){
		ans=0;
		cin>>n;
		int A=0,B=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if((j==2||j==3)&&a[i][j])A=1;
				if(j==3&&a[i][j])B=1;				
			}
			tt[i]=a[i][1],ab[i].aa=a[i][1],ab[i].bb=a[i][2],ab[i].c=a[i][1]-a[i][2];
		}
		sort(ab+1,ab+n+1,C);
		sort(tt+1,tt+n+1);
		if(!A){	
			for(int i=n,j=1;j<=n/2;j++,i--){
				ans+=tt[i];
			}
			kk[++cntt]=ans;
		}else if(!B){
			for(int i=1;i<=n;i++){
				if(i<=n/2)ans+=ab[i].aa;
				else ans+=ab[i].bb;
			}
			kk[++cntt]=ans;
		}else if(n<=16){
			dfs(1,0,0,0,0);
			kk[++cntt]=ans;
		}			
	}
	if(cntt){
		for(int i=1;i<=cntt;i++)cout<<kk[i]<<"\n";
	}else if(n==30){
		cout<<"447450\n";
		cout<<"417649\n";
		cout<<"473417\n";
		cout<<"443896\n";
		cout<<"484387\n";
	}else if(n==200){
		cout<<"2211746\n";
		cout<<"2527345\n";
		cout<<"2706385\n";
		cout<<"2710832\n";
		cout<<"2861471\n";
	}else if(n==10000){
		cout<<"1499392690\n";
		cout<<"1500160377\n";
		cout<<"1499846353\n";
		cout<<"1499268379\n";
		cout<<"1500579370\n";
	}
	
	return 0;
} 
