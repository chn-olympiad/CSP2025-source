#include<bits/stdc++.h>
using namespace std;
int n,m,z[150],k,ans,j,p;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>z[i];
	}
	k=z[1];
	sort(z+1,z+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(z[i]==k){
			ans=i;
			break;
		}
	}
	while(1){
		j+=1;
		for(int i=1;i<=n;i++){
			p++;
			if(p==ans){
				cout<<j<<' '<<i;
				return 0;
			}
		}
		j+=1;
		for(int i=n;i>=1;i--){
			p++;
			if(p==ans){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
} 
