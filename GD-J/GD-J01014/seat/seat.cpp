#include<bits/stdc++.h>
using namespace std;
int n,m,sc[300],ans[1230][1230],r_sc,cnt;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;int p=n*m; 
	for(int i=1;i<=p;i++)cin>>sc[i];
	r_sc=sc[1];sort(sc+1,sc+p+1,cmp);
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				ans[i][j]=sc[++cnt];
				if(ans[i][j]==r_sc){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		} 
		else{
			for(int j=n;j>0;j--){
				ans[i][j]=sc[++cnt];
				if(ans[i][j]==r_sc){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}//[100,100]
