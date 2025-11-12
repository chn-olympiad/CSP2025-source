#include<bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(int a,int b){return a>b;}
int sz[110];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		cin>>sz[i];
	}
	int aaa=sz[1];
	for(int i=1;i<n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(sz[i]<sz[j]){
				int res=sz[i];sz[i]=sz[j];sz[j]=res;
			}			
		}
	}
	int d=1;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(sz[d]==aaa){
					cout<<i<<" "<<j;
					return 0;
				}
				d++;
			}
		}
		else{
			for(int j=1;j<=n;j++){
				if(sz[d]==aaa){
					cout<<i<<" "<<j;
					return 0;
				}
				d++;
			}
		}
	}
	cout<<"I don't know.";
	return 0;
}
