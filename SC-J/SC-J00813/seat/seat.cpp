#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,flag,x=1,crt=1;
	cin>>n>>m;
	vector<int> a(n*m+5);
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	flag=a[1];
	sort(a.begin()+1,a.begin()+1+m*n,cmp);
	while(x<=m){
		if(x%2==1){
			for(int y=1;y<=n;y++){
				if(a[crt]==flag){
					cout<<x<<' '<<y;
				}
				crt++;
			}	
		}else{
			for(int y=n;y>=1;y--){
				if(a[crt]==flag){
					cout<<x<<' '<<y;
				}
				crt++;
			}
		}
		x++;
	}
		
	return 0;
}