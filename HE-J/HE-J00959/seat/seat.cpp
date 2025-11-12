#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define con continue
using namespace std;
int n,m,a[21][21],x,y,id,s[111];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>id;
	s[1]=id;
	for(int i=2;i<=n*m;i++){
		cin>>s[i];
	}
	sort(s+1,s+n*m+1,cmp);
	int k=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[j][i]=s[++k];
				if(s[k]==id){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				a[j][i]=s[++k];
				if(s[k]==id){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

