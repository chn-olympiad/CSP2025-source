#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn=1002;

int n,m,c,r,pos_id;
int grades[maxn];
int seats[maxn][maxn];

bool cmp(int x,int y){
	
	return x>y;
	
}

int main() {
	
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++){
		
		cin>>grades[i];
		if(i==1) pos_id=grades[i];
		
	}
	
	sort(grades+1,grades+(n*m)+1,cmp);
	
	int k=1,x=1,y=1;
	bool exch=false;
	
	while(k<=(n*m)){
		
		
		if(!exch){
			
			x=1;
			while(x<=n){
				
				//cout<<x<<' '<<y<<endl;
				seats[x][y]=grades[k];
				x++,k++;
				
			}
			exch=true;
			
		}
		
		else{
			
			x=n;
			while(x>=1){
				
				//cout<<x<<' '<<y<<endl;
				seats[x][y]=grades[k];
				x--,k++;
				
			}			
			
			exch=false;
			
		}
		
		y++;
		
	}
	
	int ans_x,ans_y;
	
	for(int i=1;i<=n;i++){
		
		for(int j=1;j<=m;j++){
			
			if(seats[i][j]==pos_id) {
				
				ans_x=i,ans_y=j;
				break;
				
			}
			
		}

	}
	
	cout<<ans_y<<' '<<ans_x<<endl;	
	return 0;
	
}

