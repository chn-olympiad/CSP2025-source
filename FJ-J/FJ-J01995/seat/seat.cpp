#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r=1,c=1,fx=0;
	cin>>n>>m;
	int l=n*m;
	int a[l]={};
	for (int i=0;i<l;i++){
		cin>>a[i];
	}
	int mb=a[0];
	sort(a,a+l);
	for (int i=l-1;i>=0;i--){
		if (a[i]==mb){
			cout<<c<<" "<<r; 
			return 0;
		}
		if (fx==0){
			r++;
			if (r>n){
				c++;
				r=n;
				fx=1;
			}
		}
		else if (fx==1){
			r--;
			if (r<1){
				c++;
				r=1;
				fx=0;
			} 
		}
	}
	return 0;
}

