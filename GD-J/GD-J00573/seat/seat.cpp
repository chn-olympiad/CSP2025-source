#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,b[105],k,x;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&b[i]);
	}
	k=b[1];
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2){
			for(int j=1;j<=m;j++){
				x++;
				if(b[x]==k){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
		else{
			for(int j=m;j>0;j--){
				x++;
				if(b[x]==k){
					cout<<j<<" "<<i;
					return 0;
				}
			}	
		}
	}
	return 0;
}

