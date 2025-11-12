#include<bits/stdc++.h>
#define thinktwice return
#define code 0
#define once ;
using namespace std;
int n,m,book,a[11451],e[114][114],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	book=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				e[i][j]=a[++cnt];
				if(e[i][j]==book){
					cout<<i<<" "<<j<<endl;
				}
			}
		}
		else{
			for(int j=m;j>=1;j--){
				e[i][j]=a[++cnt];
				if(e[i][j]==book){
					cout<<i<<" "<<j<<endl;
				}
			}
		}
	}
	thinktwice code once
}
