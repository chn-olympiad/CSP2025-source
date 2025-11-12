#include<iostream>
#include<algorithm>
using namespace std;
int a[2][1000001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				a[0][cnt]=i;
				a[1][cnt]=j;
				cnt++;
			}
			
		}
		if(i%2==0){
			for(int j=m;j>=1;j--){
				a[0][cnt]=i;
				a[1][cnt]=j;
				cnt++;
			}
			
		}
	}
	int tmp=n*m,R,r_i;
	int b[tmp];
	for(int i=0;i<n*m;i++) cin>>b[i];
	R=b[0];
	sort(b,b+tmp);
	for(int i=0;i<n;i++){
		if(R==b[i]) r_i=tmp-i;
	}
	cout<<a[0][r_i]<<" "<<a[1][r_i];
	return 0;
}