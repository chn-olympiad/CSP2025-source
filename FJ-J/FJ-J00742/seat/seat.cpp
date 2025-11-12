#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int grade=a[1],k=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				if(a[k]==grade)cout<<i<<" "<<j<<endl;
				k++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[k]==grade)cout<<i<<" "<<j<<endl;
				k++;
			}
		}
	}
	return 0;
}
