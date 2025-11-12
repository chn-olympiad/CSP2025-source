#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int s[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
			cin>>s[i];
	}
	int p=s[1];
	sort(s+1,s+m*n+1,cmp);
	int i=0,j=0,w=0;
	while(m>=i){
		i++;
		if(i%2!=0){
		j=1;
			while(n>=j){
				w++;
				a[i][j]=s[w];
				j++;
			}
		}
		if(i%2==0){
			j=n;
			while(j>=1){
				w++;
				a[i][j]=s[w];
				j--;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==p){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
}
