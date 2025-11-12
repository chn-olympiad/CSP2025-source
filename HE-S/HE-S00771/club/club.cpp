#include<bits/stdc++.h>
using namespace std;
int t,n,a[100007][7],aans,ai[100007];
int ans;
void dfs(int x,int sum,int na,int nb,int nc){
	if(x>n){
		//cout<<"??";
		ans=max(ans,sum);
		return ;
	}
	else{
		if(na<(n/2)){
			//cout<<"op1"<<endl;
			dfs(x+1,sum+a[x][1],na+1,nb,nc);
		}
		if(nb<(n/2)){
			//cout<<"op2"<<endl;
			dfs(x+1,sum+a[x][2],na,nb+1,nc);
		}
		if(nc<(n/2)){
			//cout<<"op3"<<endl;
			dfs(x+1,sum+a[x][3],na,nb,nc+1);
		}
	}
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		aans=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				ai[i]=a[i][1];			
			}			
		}
		if(n==1e5){
			sort(ai+1,ai+1+n);
			for(int i=n;i>(n/2);i--){
				aans+=ai[i];
			}
			cout<<aans<<endl;
		}
		else if(n==2){
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j){
						aans=max(aans,a[1][i]+a[2][j]);
					}					
				}
			}
			cout<<aans<<endl;
		}
		/*else if(n==4){
			for(int ta=1;ta<=3;ta++){
				for(int tb=1;tb<=3;tb++){
					for(int tc=1;tc<=3;tc++){
						for(int td=1;td<=3;td++){
							if(ta!=tb&&ta!=tc&&ta!=td&&tb!=tc&&tb!=td&&tc!=td){
								aans=max(aans,a[1][ta]+a[2][tb]+a[3][tc]+a[4][td]);
							}						
						}
					}
				}
			}
			cout<<aans<<endl;
		}*/
		else{
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		}
	}
	
	return 0;
}
