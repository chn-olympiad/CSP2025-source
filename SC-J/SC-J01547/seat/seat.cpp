#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int a[105],mp[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,aim;
	cin>>n>>m;
	int l=n*m;
	for(int i=1;i<=l;i++) cin>>a[i];
	aim=a[1];
	sort(a+1,a+l+1,cmp);
	int k=1;
	for(int j=1;j<=m;j++){
		int op=pow(-1,j-1);
		if(op==1){
			for(int i=1;i<=n;i++){
				mp[i][j]=a[k];k++;
			}
		}else{
			for(int i=n;i>=1;i--){
				mp[i][j]=a[k];k++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==aim){
				cout<<j<<" "<<i;
				return 0;
			} 
		}
	}
	
	return 0;
}