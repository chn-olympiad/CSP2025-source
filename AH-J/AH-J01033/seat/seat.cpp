#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
long long n,m,b[10010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long c=n*m;
	for(int i=1;i<=c;i++){
		cin>>b[i];
	}
	long long a=b[1],ans=1;
	sort(b+1,b+c+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				if(b[ans++]==a){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else if(i%2==0){
			for(int j=n;j>=1;j--){
				if(b[ans++]==a){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
