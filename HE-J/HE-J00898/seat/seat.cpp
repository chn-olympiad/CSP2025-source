#include<bits/stdc++.h>
using namespace std;
long long n,m,ren[100000010],r;
long long rr[10010][10010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>ren[i];
	}
	r=ren[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(ren[i]>ren[j]){
				swap(ren[i],ren[j]);
			}
		} 
	}
	int t=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				rr[i][j]=ren[t];
				if(t>=n){
					t++;
					continue;
				}
				t++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				rr[i][j]=ren[t];
				if(t>=n){
					t++;
					continue;
				}
				t++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(rr[i][j]==r){
				cout<<i<<" "<<j;
				break; 
			}
		}
	}
	return 0; 
} 
