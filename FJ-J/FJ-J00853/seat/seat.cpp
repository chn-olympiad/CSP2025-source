#include<bits/stdc++.h>
using namespace std;
int n,m,b[21],ans,q=1;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int cnt=m*n;
	for(int i=1;i<=cnt;i++) cin>>b[i];
	ans=b[1];
	sort(b+1,b+1+cnt,cmp);
	int ct=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
		    for(int j=1;j<=n;j++){
			    ct++;
			    if(b[ct]==ans){
			    	cout<<i<<" "<<j;
			    	return 0;
				}
		    }
		}
		else{
			for(int j=n;j>=1;j--){
				ct++;
				if(b[ct]==ans){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
