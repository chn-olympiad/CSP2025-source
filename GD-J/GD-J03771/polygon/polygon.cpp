#include<bits/stdc++.h>
 using namespace std;
int n,m[5005],sum,maxn,vis[5005],flag=1;
bool pd(int x,int y){
	return y>x*2;
}
void f(int x,int mx,int sm){
	if(x==0){
		if(pd(mx,sm))
			sum++;
		return ;
	}
	x--;
	for(int i=flag;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			flag=i;
			f(x,max(mx,m[i]),sm+m[i]);
			vis[i]=0;
		}
	}	
	return ;
}
 int main(){
	freopen("polygon.in","r",stdin);
 	freopen("polygon.out","w",stdout);
	cin>>n;	
	if(n==3){
		for(int i=1;i<=n;i++){
			cin>>m[i];
		}
		f(n,0,0);
		cout<<sum;
	}
	else {
		for(int i=1;i<=n;i++)
			cin>>m[i];
			
		for(int i=3;i<=n;i++){
			for(int j=1;j<=n;j++)
				vis[j]=0;
			flag=1;
			f(i,0,0);
		}
		cout<<sum;
	}
  fclose(stdin);
 	fclose(stdout);
 	return 0;
 }
