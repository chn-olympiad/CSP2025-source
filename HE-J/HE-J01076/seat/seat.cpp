#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int rs;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			rs=a[i];
		}
	}
	sort(a+1,a+1+(n*m),cmp);
	int pd=0;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				pd++;
				if(a[pd]==rs){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=1;j<=n;j++){
				pd++;
				if(a[pd]==rs){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
