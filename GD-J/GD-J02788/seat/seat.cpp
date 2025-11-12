#include<bits/stdc++.h>
using namespace std;
int a[15][15],cnt=0;
pair<int,int> b[120]; 
int n,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i].first;b[i].second=i;
	}
	sort(b+1,b+(1+(n*m)));
	cnt=n*m+1;
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				cnt--;
				if(b[cnt].second==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else {
			for(int j=n;j>=1;j--){
				cnt--;
				if(b[cnt].second==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}	
	}
	return 0;
}

