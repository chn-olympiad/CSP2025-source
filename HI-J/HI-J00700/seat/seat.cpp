#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r;
bool cmp(int A,int B){
	return A>B;
}
void init(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)r=a[i]; 
	}
	sort(a+1,a+1+n*m,cmp); 
	//for(int i=1;i<=n*m;i++)cout<<a[i]<<" ";
	//cout<<"\n"<<r<<"\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	init();
	int ansx,ansy;
	for(int i=1;i<=m;i++)
		if(i%2)
			for(int j=1;j<=n;j++){
				//cout<<i<<' '<<j<<" "<<a[(i-1)*m+j]<<"\n";
				if(a[(i-1)*m+j]==r){
					cout<<i<<" "<<j<<"\n";
					return 0;
				}
			} 
		else 
			for(int j=n;j>=1;j--){
				//cout<<i<<' '<<j<<" "<<a[(i-1)*m+(n-j+1)]<<"\n";
				if(a[(i-1)*m+(n-j+1)]==r){
					cout<<i<<" "<<j<<"\n";
					return 0;
				}
			}
	return 0;
}

