#include <bits/stdc++.h>
using namespace std;
int const N=1e5;
int t,c=2;
int ans=0;
int d[3]={1,2,3};
int a[N][3];
void yun(int n){
	
	ans=0;
	c=2;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
			}
		}
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			for(int s=0;s<3;s++){
			if(a[i][j]<a[i][s]){
				swap(a[i][j],a[i][s]);}
				}
			}
		}
	for(int i=0;i<n;i++){
		ans+=a[i][c];
		}
	cout<<ans<<endl;
	}

int main(){
	int n;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	cin>>n;
	for(int i=0;i<t;i++){
		yun(n);
		
		
		
	}
	return 0;
}
