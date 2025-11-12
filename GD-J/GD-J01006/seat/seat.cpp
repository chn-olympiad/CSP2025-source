#include<bits/stdc++.h>
using namespace std;
int a[19][19],n,m,b[19][19],d[109];
int s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			s++;
			d[s]=a[i][j];
		}
	}
	int c=a[1][1];
	sort(d+1,d+1+s,cmp);
	s=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=d[s];
			s++;
		}
	}
	s=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[i][j]=a[s/m+1][s%m+1];
				s++;
				if(b[i][j]==c){
			cout<<i<<" "<<j;
			return 0;
			}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				b[i][j]=a[s/m+1][s%m+1];
				s++;
				if(b[i][j]==c){
			cout<<i<<" "<<j;
			return 0;
			}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			
			
		}
	}
	return 0;
} 
