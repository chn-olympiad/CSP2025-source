#include<bits/stdc++.h>
using namespace std;
int n,m;
int r=1,c=0;
int v[100010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>v[i];
	}
	int R=v[1];
	sort(v+1,v+n*m+1);
	int s=n*m;
	while(1){
		if(r==1){
			c++;
			while(r<=n){
				if(R==v[s]){
					cout<<c<<" "<<r;
					return 0;
				}
				s--;
				r++;
			}
			r--;
		}
		else if(r==n){
			c++;
			while(r>=1){
				if(R==v[s]){
					cout<<c<<" "<<r;
					return 0;
				}
				s--;
				r--;
			}
			r++;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
