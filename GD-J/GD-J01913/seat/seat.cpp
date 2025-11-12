#include<bits/stdc++.h>
using namespace std;
int a[1005];
int n,m,z,s,k,num;
bool d;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	z=n*m;
	cin>>s;
	a[1]=s;
	for(int i=2;i<=z;i++){
		cin>>a[i];
	}
	sort(a+1,a+z+1); 
	for(int i=z;i>=1;i--)if(s==a[i])num=z-i+1;
	for(int i=1;i<=m;i++){
		if(!d){
			for(int j=1;j<=n;j++){
				k++;
				if(k==num)cout<<i<<" "<<j;
			}
			d==1;
		}else{
			for(int j=n;j>=1;j--){
				k++;
				if(k==num)cout<<i<<" "<<j;
			}
			d==0;
		}
	}
	return 0;
}
