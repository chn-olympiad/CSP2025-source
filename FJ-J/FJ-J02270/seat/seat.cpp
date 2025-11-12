#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int ar,sum;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	sum=n*m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	ar=a[1];
	sort(a+1,a+sum+1);
	for(int i=sum;i>=1;i--){
		if(a[i]==ar){
			int num=sum-i+1;
			int x=num/n,y=num%n,c,r;
			if(y==0){
				c=x;
				if(x%2==1){
					r=n;
				}else{
					r=1;
				}
			}else{
				if(x%2==0){
					c=x+1;
					r=y;
				}else{
					c=x+1;
					r=n-y+1;
				}
			}
			cout << c << ' ' << r << endl;
			return 0;
		}
	}
}

