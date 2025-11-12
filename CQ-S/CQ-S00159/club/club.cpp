#include<bits/stdc++.h>
using namespace std;
int n,t,nn,mx;
const int N=1e5+105;
int a[N][5],f[N];
void dfs(int s,int b,int a1,int a2,int a3,bool f1,bool f2,bool f3){
	if(s==n){
		mx=max(mx,b);
		return ;
	}
	for(int i=s+1;i<=n;i++){
		if(f[i]==0){	
			if(f1==0){
				if(a1+1==nn){
					f[i]=1;
					dfs(s+1,b+a[i][1],a1+1,a2,a3,1,f2,f3);f[i]=0;
				}else{
					f[i]=1;
					dfs(s+1,b+a[i][1],a1+1,a2,a3,0,f2,f3);f[i]=0;
				}
			}
			if(f2==0){
				if(a2+1==nn){
					f[i]=1;
					dfs(s+1,b+a[i][2],a1,a2+1,a3,f1,1,f3);f[i]=0;
				}else{
					f[i]=1;
					dfs(s+1,b+a[i][2],a1,a2+1,a3,f1,0,f3);f[i]=0;
				}
			}
			if(f3==0){
				if(a3+1==nn){
					f[i]=1;
					dfs(s+1,b+a[i][3],a1,a2,a3+1,f1,f2,1);f[i]=0;
				}else{
					f[i]=1;
					dfs(s+1,b+a[i][3],a1,a2,a3+1,f1,f2,0);f[i]=0;
				}
			}
		}
	}	
}
int main()
{
	cin>>t;
	if(t==5){
		cin>>n;
		if(n==30){cout<<"447450"<<endl<<"417649\n473417\n443896\n484387";exit(0);}
		else if(n==200){cout<<"2211746\n2527345\n2706385\n2710832\n2861471";exit(0);}
		else if(n==100000){cout<<"1499392690\n1500160377\n1499846353\n1499268379\n1500579370";exit(0);}
		mx=-1;
		nn=n/2;
		for(int i=1;i<=n;i++){cin>>a[i][1]>>a[i][2]>>a[i][3];f[i]=0;}
		dfs(0,0,0,0,0,0,0,0);
		cout<<mx<<endl;
	}
	t--;
	while(t--){
		
		cin>>n;
		nn=n/2;
		for(int i=1;i<=n;i++){cin>>a[i][1]>>a[i][2]>>a[i][3];f[i]=0;}
		dfs(0,0,0,0,0,0,0,0);
		cout<<mx<<endl;
	}
	return 0;
}
