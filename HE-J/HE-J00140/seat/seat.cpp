#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],rg,r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
		if(i==1){
			rg=a[i];
		}
	}
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=m*n;i++){
		if(a[i]==rg){
			r=i;
		}
	}
	int hang=0,lie=0;
	if(r%n==0){
		lie=r/n;
		if(lie%2==0){
			hang=1;
		}else{
			hang=n;
		}
	}else{
		lie=r/n+1;
		if(lie%2==0){
			hang=n-(r%n-1);
		}else{
			hang=r%n;
		}
	}
	cout<<lie<<" "<<hang;
	return 0;
}
