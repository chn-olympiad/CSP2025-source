#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100001][4],x,y,z,daan=0;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==2){
			long long a1,a2,b1,b2,c1,c2,aa,bb,cc;
			cin>>a1>>b1>>c1>>a2>>b2>>c2;
			aa=max({a1+b2,a1+c2,a2+b1,a2+c1});
			bb=max({b1+a2,b1+c2,b2+a1,b2+c1});
			cc=max({c1+a2,c1+b2,c2+a1,c2+b1});
			cout<<max({aa,bb,cc})<<"\n";
		}
		else{
			daan=0,x=0,y=0,z=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					cin>>a[i][j];
				}
			}
			for(int i=1;i<=n;i++){
				long long k=max(a[i][1],max(a[i][2],a[i][3]));
				if(k==a[i][1]){
					if(x<n/2){
						daan+=k;
						x++;
					}
					else{
						long long g=max(a[i][2],a[i][3]);
						if(g==a[i][2]){
							if(y<n/2){
								daan+=g;
								y++;
							}
							else{
								daan+=a[i][3];
								z++;
							}
						}
						if(g==a[i][3]){
							if(z<n/2){
								daan+=g;
								z++;
							}
							else{
								daan+=a[i][2];
								y++;
							}
						}
					}
				}
				if(k==a[i][2]){
					if(y<n/2){
						daan+=k;
						y++;
					}
					else{
						long long g=max(a[i][1],a[i][3]);
						if(g==a[i][1]){
							if(x<n/2){
								daan+=g;
								x++;
							}
							else{
								daan+=a[i][3];
								z++;
							}
						}
						if(g==a[i][3]){
							if(z<n/2){
								daan+=g;
								z++;
							}
							else{
								daan+=a[i][1];
								x++;
							}
						}
					}
				}
				if(k==a[i][3]){
					if(z<n/2){
						daan+=k;
						z++;
					}
					else{
						long long g=max(a[i][1],a[i][2]);
						if(g==a[i][1]){
							if(x<n/2){
								daan+=g;
								x++;
							}
							else{
								daan+=a[i][2];
								y++;
							}
						}
						if(g==a[i][2]){
							if(y<n/2){
								daan+=g;
								y++;
							}
							else{
								daan+=a[i][1];
								x++;
							}
						}
					}
				}
			}
			cout<<daan<<"\n";
		}
	}
	return 0;
}
