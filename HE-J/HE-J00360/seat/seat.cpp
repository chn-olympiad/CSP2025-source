#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010];
bool cmp(int l,int r){
	if(l>r) return true;
	return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+n*m+2,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;){
		for(int j=1;j<m;j++){
			if(y%2==0){
				x--;
			}else{
				x++;
			}
			i++;
			if(a[i]==t){
				cout<<y<<" "<<x;
			}
		}
		y++;
		i++;
		if(a[i]==t){
			cout<<y<<" "<<x;
		}
	}
	return 0;
}
