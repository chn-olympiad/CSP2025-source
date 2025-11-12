#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,s[15][15],x=0,y=1,num[105],p,ans;
bool b=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>p;
		if(i==1)ans=p;
		num[p]++;
	}
	for(int i=100;i>=0;i--){
		if(num[i]>=0){
			while(num[i]--){
				if(!b){
					if(x==n){
						b=1;
						y++;
						//s[x][y]=i;
						continue;
					}
					x++;
					//s[x][y]=i;
				}
				else{
					if(x==1){
						b=0;
						y++;
						//s[x][y]=i;
						continue;
					}
					x--;
					//s[x][y]=i;
				}
			}
		}
		if(i==ans){
			cout<<y<<" "<<x;
			return 0;
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<s[i][j]<<" ";
		}
		cout<<endl;
	}*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2 2
99 100 97 98

3 3
94 95 96 97 98 99 100 93 92
*/
