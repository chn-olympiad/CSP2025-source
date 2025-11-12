#include<bits/stdc++.h>
using namespace std;
int b[100001];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>b[i];
	int score=b[1];
	sort(b+1,b+(n*m)+1,cmp);
	int z=1,j=1;bool w=1;
	for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(b[z]==score){
					cout<<i<<' '<<j;
					return 0;
				}
				z++;
			}
			i++;
			for(int j=n;j>=1;j--){
					if(b[z]==score){
						cout<<i<<' '<<j;
						return 0;
					}
				z++;			
			}
	}
	return 0;
}
