#include<bits/stdc++.h>
using namespace std;
int n,m,R;
int marks[105];
int places[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>marks[i];
	R=marks[1];
	sort(marks+1,marks+1+(n*m));
	int k=n*m;
	for(int j=1;j<=m;j++){
		if(j%2!=0){
			for(int i=1;i<=n;i++){
				places[i][j]=marks[k];
				if(places[i][j]==R){
					cout<<j<<' '<<i;
					return 0;
				}else k--;
			}
		}
		else{
			for(int i=n;i>=1;i--){
				places[i][j]=marks[k];
				if(places[i][j]==R){
					cout<<j<<' '<<i;
					return 0;
				}else k--;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

