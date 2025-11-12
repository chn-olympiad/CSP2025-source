#include<bits/stdc++.h>
using namespace std;
int n,m,h,u,cnt;
int a[10000];
bool f1=false;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	int b[n][m];
	for(int i=0;i<k;i++){
		cin>>a[i];
	}
	int x=0,y=0,r=a[0];
	for(int j=0;j<k;j++){
		for(int i=0;i<k;i++){
			if(max(a[i],a[i+1])==a[i+1]){
				h=a[i];
				u=a[i+1];
				a[i]=u;
				a[i+1]=h;	
			}
		}
	}
	
	for(int j=0;j<(n/2)+1;j++){
		for(int i=0;i<n;i++){
			b[x+i][y]=a[cnt];
			cnt++;
		}
		y++;
		for(int i=0;i<n;i++){
			b[n-i][y]=a[cnt];
			cnt++;
		}
		y++;
	}
	
	for(int j=0;j<n;j++){
		for(int i=0;i<m;i++){
			if(r==b[j][i]){
				cout<<i+1<<" "<<j+1;
			}
		}
	}
	return 0;
}
