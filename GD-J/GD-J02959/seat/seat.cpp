#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>a;int pos[107][107];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int l;cin>>l;
		a.push_back(l);
	}int b=a[0];sort(a.begin(),a.end());
	int k=1;
	for(int i=1;i<=n;i++){
		if(k==1){
			for(int j=1;j<=m;j++){
				pos[i][j]=a.back();
				if(pos[i][j]==b){
					cout<<i<<' '<<j;return 0;
				}
				a.pop_back();
			}k=m;
		}
		else if(k==m){
			for(int j=m;j>=1;j--){
				pos[i][j]=a.back();
				if(pos[i][j]==b){
					cout<<i<<' '<<j;return 0;
				}
				a.pop_back();
			}k=1;
		}
	}
	return 0;
}
