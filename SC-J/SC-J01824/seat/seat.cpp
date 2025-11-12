#include<bits/stdc++.h>
using namespace std;
int n,m,s[10000],a,b[100][100],t=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
		if(i==1){
			a=s[i];
		}
	}
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				if(s[t]==a){
					cout<<i<<' '<<j;
					return 0;
				}
				t++;
			}
		}else{
			for(int j=n;j>=1;j--){
				if(s[t]==a){
					cout<<i<<' '<<j;
					return 0;
				}
				t++;
			
			}
		}
	}
	return 0;
}