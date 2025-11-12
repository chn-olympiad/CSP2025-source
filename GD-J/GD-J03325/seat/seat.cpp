#include<bits/stdc++.h>

using namespace std;

int a[15][15],b[105],n,m,dx = 1,dy = 1,aim,cnt = 0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
		if(i==1)
			aim = b[i];
	}
	
	sort(b+1,b+1+n*m,cmp);
	
	//ต๗สิ 
	/*for(int i=1;i<=n*m;i++){
		cout<<b[i]<<" ";
	}
	cout<<aim; 
	cout<<endl;*/
	
	int i=1,dir = 1;
	int ans = n*m;
	while(cnt!=ans){
		
		/*if(aim==a[dx][dy])
			cout<<dx<<" "<<dy;*/
			
		a[dx][dy] = b[i];
		//cout<<"dx:"<<dx<<" "<<"dy:"<<dy<<" "<<"dir:"<<dir<<" "<<"b[i]:"<<b[i]<<endl;	
		
		if(dir==1){
			if(dx==n){
				dy++;
				dir = 2;
			}
			else dx++;
		}
		else if(dir==2){
			if(dx==1){
				dx++;
				dir = 1;
			}
			else if(dx==n){
				dir = 0;
				dx--;
			}
				
		}
		else if(dir==0){
			if(dx==1){
				dy++;
				dir = 2;
			}
			else dx--;
		}
		
		i++;cnt++;
	}
	//a[dx][dy] = b[n*m];
	//ต๗สิ 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==aim){
				cout<<j<<" "<<i;break; 
			}
		} 
		//cout<<"\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
