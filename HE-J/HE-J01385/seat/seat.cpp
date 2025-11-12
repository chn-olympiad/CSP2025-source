#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int k=n*m-1;
	int b=a[0];
	sort(a,a+n*m);
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				if(b==a[k]){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
				k--;
			}
		}else{
			for(int j=n-1;j>=0;j--){
				if(b==a[k]){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
				k--;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
