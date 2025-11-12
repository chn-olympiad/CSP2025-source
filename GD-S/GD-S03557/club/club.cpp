#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+500;
int e[N][4];
int m[N];
int ans[4];
int flag[N];
int vis[4];
int sum;
int n,lim;
int li[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		sum = 0;
		memset(vis,0,sizeof(vis));
		memset(ans,0,sizeof(ans));
		cin >> n;
		//ÌØÅĞ
		if(n==2){

			int f,s,t,ans=0;
			for(int i=1;i<=n;i++) cin>>e[i][1]>>e[i][2]>>e[i][3];
			//1 2
			ans=e[1][1]+e[2][2];
			//1 3
			ans=max(ans,e[1][1]+e[2][3]);
			//2 1
			ans=max(ans,e[1][2]+e[2][1]);
			//2 3
			ans=max(ans,e[1][2]+e[2][3]);
			//3 1
			ans=max(ans,e[1][3]+e[2][1]);
			//3 2
			ans=max(ans,e[1][3]+e[2][2]);
			cout << ans << endl;
			continue; 
		}

		else{
			lim = n/2;
			li[1]=li[2]=li[3]=lim;
			for(int i=1;i<=n;i++){
				cin>>e[i][1]>>e[i][2]>>e[i][3];
			}
			/*
			while(lim1+lim2+lim3>=n){
				for(int i=1;i<=3;i++){
					for(int j=1;j<=n;j++){
						if(vis[i]==li[i]) break;
						while(vis[i]<li[i] && flag[j]==0){
							flag[j]=1;
							vis[i]++;
							ans[i] += e[j][i];
						}
					}
					
				}
				
			} 
			*/
			
			for(int i=1;i<=6;i++){
				memset(vis,0,sizeof(vis));
				memset(ans,0,sizeof(ans));
				for(int j=1;j<=n;j++){
					if(i==1){
						if(vis[1]!=lim){
							vis[1]++;
							ans[1]+=e[j][1];
						}
						else if(vis[2]!=lim){
							vis[2]++;
							ans[2]+=e[j][2];
						}
						else{
							vis[3]++;
							ans[3]+=e[j][3];
						}
					}
					else if(i==2){
						if(vis[1]!=lim){
							vis[1]++;
							ans[1]+=e[j][1];
						}
						else if(vis[3]!=lim){
							vis[3]++;
							ans[3]+=e[j][3];
						}
						else{
							vis[2]++;
							ans[2]+=e[j][2];
						}
					}
					else if(i==3){
						if(vis[2]!=lim){
							vis[2]++;
							ans[2]+=e[j][2];
						}
						else if(vis[1]!=lim){
							vis[1]++;
							ans[1]+=e[j][1];
						}						
						else{
							vis[3]++;
							ans[3]+=e[j][3];
						}
					}
					else if(i==4){
						if(vis[2]!=lim){
							vis[2]++;
							ans[2]+=e[j][2];
						}
						else if(vis[3]!=lim){
							vis[3]++;
							ans[3]+=e[j][1];
						}						
						else{
							vis[1]++;
							ans[1]+=e[j][1];
						}
					}
					else if(i==5){
						if(vis[3]!=lim){
							vis[3]++;
							ans[3]+=e[j][3];
						}
						else if(vis[1]!=lim){
							vis[1]++;
							ans[1]+=e[j][1];
						}						
						else{
							vis[2]++;
							ans[2]+=e[j][2];
						}
					}
					else{
						if(vis[3]!=lim){
							vis[3]++;
							ans[3]+=e[j][3];
						}
						else if(vis[2]!=lim){
							vis[2]++;
							ans[2]+=e[j][2];
						}						
						else{
							vis[1]++;
							ans[1]+=e[j][1];
						}							
					}
				}	
				cout << "ans×Ü£º" << ans[1] << ' ' << ans[2] << ' ' << ans[3] << endl;
				sum=max(sum,ans[1]+ans[2]+ans[3]);	
			}
			
			cout << sum << endl;	
		
		}		
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

