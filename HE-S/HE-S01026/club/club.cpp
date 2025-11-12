#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,t;
int a[6][N][5];
int ans;
int v[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int gou=n/2;
		ans=0;
		memset(v,0,4);
		for(int j=1;j<=n;j++){
			int y=0,vy=N;
			int op=0,vop=0;
			for(int z=1;z<=3;z++){
				int x;
				cin>>x;
				a[i][j][z]=x;
				if(y<x){
					y=x;
					op=z;
				}
				else if(vy>x){
					vy=x;
					vop=z;
				}
			}
			if(v[op]==gou){
				for(int z=1;z<=3;z++){
					if(z!=op&&z!=vop){
						ans+=a[i][j][z];
						v[z]++;
					}
				}
				
			}
			else{
				ans+=y;
				v[op]++;
			}
			
		}	
		cout<<ans<<endl;
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


