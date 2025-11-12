#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int a[1005];
int b[1005];
bool comp(int p,int q){
	return p>q;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int o=1,k=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[o]=a[i];
		o++;
	}
	k=a[1];
	o--;
	sort(b+1,b+1+o,comp);
	int l=1;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(b[l]==k){
					cout<<i<<' '<<j;
					return 0;
				}
				l++;
			}	
		}
		else{
			for(int j=m;j>=1;j--){
				if(b[l]==k){
					cout<<i<<' '<<j;
					return 0;
				}
				l++;
			}
		} 
	}
	return 0;
}
