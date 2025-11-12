#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int a[30];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int ans=a[0];
	sort(a,a+n*m,cmp);
	int l=1;
	int h=1;
	int cnt=0;
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			if(a[cnt]==ans){
				cout<<l<<" "<<h;
			}
			if(i%2==1){
				h++;
			}else{
				h--;
			}
			cnt++;
			if(a[cnt]==ans){
				cout<<l<<" "<<h;
			}
		}
		l++;
		cnt++;
		if(a[cnt]==ans){
			cout<<l<<" "<<h;
		}
	}
	return 0;
}
