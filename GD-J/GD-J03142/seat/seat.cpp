#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
short m,n;
short arr[15][15];
short sr[105];
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	
	cin>>m>>n;
	short t=n*m,fst;
	cin>>fst;
	sr[1]=fst;
	for(int i=2;i<=t;++i)cin>>sr[i];
	sort(sr+1,sr+t+1);
	for(int i=1;i<=m;++i){
		if(i&1){
			for(int j=1;j<=n;++j){
				arr[i][j]=sr[t--];
				if(arr[i][j]==fst)cout<<i<<' '<<j<<endl;
			}
		}
		else{
			for(int j=n;j>0;--j){
				arr[i][j]=sr[t--];
				if(arr[i][j]==fst)cout<<i<<' '<<j<<endl;
			}
		}
	}
	
 return 0;
}
