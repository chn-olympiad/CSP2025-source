#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int n,m,q[N];
int tmp;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<n*m+1;i++){
		cin>>q[i];
	}
	tmp=q[1];
	sort(q+1,q+(n*m)+1,cmp);
	for(int i=1,zw=1;i<m+1;i++){
		if(i%2){
			for(int j=1;j<n+1;j++,zw++){
				if(q[zw]==tmp){
					cout<<i<<" "<<j;
					return 0;
				}
			} 
		}
		else{
			for(int j=n;j>0;j--,zw++){
				if(q[zw]==tmp){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
