#include<bits/stdc++.h>

using namespace std;


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;cin >> n >> m >> k;	int pass[n+1][n+1];
	int arr[1+n][n+1];
	bool rudu[n+1];
	for(int i = 0;i <= n;i++){
		rudu[i] = 0;
	}
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= n;j++){
			arr[i][j] = -1;pass[i][j]=0;
		}
	}
	for(int i = 0;i < m;i++){
		int a,b,c;cin >> a >> b >> c;pass[a][b] = 1;
		arr[a][b] = c;rudu[a] ++;rudu[b]++;arr[b][a] = c;
	}
	int fff = 0;
	
	for(int i = 0;i < k;i++){
		int cs ;int sc[n];cin >> cs;bool is_u = 0;
		for(int i = 0;i < n;i++){
			cin >> sc[i];if(sc[i] == 0){
				fff = 1;
			}
		}
		for(int j = 0;j < n;j++){int countt = 0;
			for(int in = j+1;in < n;in++){
				if(!is_u){
					countt += cs;
				}
				countt = countt +sc[in]+sc[j];
				if(countt <= arr[in][j]){
					is_u = 1;
					arr[in][j] = countt;arr[j][in] = countt;
				}
			}
		}
		
	}
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= n;j++){
			if(arr[i][j]!=-1 and rudu[j] == 1){
				pass[i][j] = pass[j][i] = 1;
			}
		}
	}
	
	vector<bool>is_pass(n+1,0);int fir=0;
	for(int i = 0;i <= n;i++){
		if(rudu[i] >= 2){
			fir=i;break;
		}
	}if(fir){
	vector<int>last ;
	last[fir] = fir;
	int temp = fir;
		queue<int>qe;
		qe.push(fir);
		is_pass[fir] = 1;
		while(!qe.empty()){
				temp = qe.front();qe.pop();
				for(int u = 0;u <= n;u++){
					int i = arr[temp][u];
					if(is_pass[u]){
						int flag1 = u,flag2 = temp;
						int j = last[u];int t = last[temp];while(true){
							if(j==t){
								break;
							}else{
								if(arr[j][last[j]] >= arr[flag1][flag2]){
									flag1 = u;flag2 = last[u];
								}if(arr[t][last[t]] >= arr[flag1][flag2]){
									flag1 = u;flag2 = last[u];
								}
								j = last[j];t = last[t];
							}
							
						}
						
						pass[flag1][flag2] = pass[flag2][flag1] = 0;
						
					}
					
					
					if(i != -1 and is_pass[u] == 0){
						qe.push(i);is_pass[u] = 1;last[u] = temp;
					}
					
				}
				
		}
		
	}
			
	if(!fff)		{
	
	int countty = 0;
		for(int i = 0;i <=n;i++){
			for(int j = i+1;j <= n;j++){
				if(pass[i][j]){
					countty += arr[i][j];
				}
			}
		}
		cout << countty;
		}
	else{
		cout << 0;
	}
	
	
return 0;	
}
