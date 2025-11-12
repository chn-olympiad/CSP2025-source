#include<bits/stdc++.h>
using namespace std;
int n,m,b[110],p=0,t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
	    cin>>b[i];
		if(i==1) t=b[i];
	} 
	sort(b+1,b+1+n*m,greater<int>());
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				p++;
				if(b[p]==t){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
		else{
			for(int j=m;j>=1;j--){
				p++;
				if(b[p]==t){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
} 
