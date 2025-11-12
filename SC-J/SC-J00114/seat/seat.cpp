#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int num=n*m;
	for(int i=1;i<=num;i++){
		cin>>a[i];
	}	
	int k=a[1];
	sort(a+1,a+num+1);
	int l=num;
	int c=1,r=1;
	while(a[l]!=k){
		if(c%2==1){
			if(r==n){
				c++;
			}
			else{
				r++;
			}
		}
		else{
			if(r==1){
				c++;
			}
			else{
				r--;
			}
		}
		l--;
	}
	cout<<c<<' '<<r;
	return 0;
}