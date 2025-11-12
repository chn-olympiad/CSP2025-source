#include<bits/stdc++.h>
using namespace std;
int a[150];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			a1=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	int l=1,r=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			cout<<r<<" "<<l;
			break;
		}
		if(r%2==1&&l<n){
			l++;
			continue;
		}
		if(r%2==0&&l>1){
			l--;
			continue;
		}
		r++;
	}
	
	return 0;
}
