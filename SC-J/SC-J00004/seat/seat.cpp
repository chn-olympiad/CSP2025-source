#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k,per=0;
	cin>>n>>m>>k;
	vector<int> a(n*m,0);
	a[0]=k;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end(),cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				if(a[per]==k){
					cout<<j<<" "<<i;
					return 0;
				}
				else per++;
			}
		}
		else{
			for(int i=n;i>=1;i--){
				if(a[per]==k){
					cout<<j<<" "<<i;
					return 0;
				}
				else per++;
			}
		}
	}
//
}