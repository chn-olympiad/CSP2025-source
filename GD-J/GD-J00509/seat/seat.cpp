#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long a[N],b[105][105],n,m,c,r=1;
bool bmn(int h,int p) {
	if(h>p) return true;
	else return false;
}
int main() {
freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+n*m+1,bmn);
int k=1,j=1;
	for(int i=1; i<=11;i++) {
		if(k<=n*m) {
			if(i>=n&&j%2==1) {
				j++;
				i=n;
				b[i][j]=a[k];
				//cout<<b[i][j];
				if(c==b[i][j]) {
					cout<<j<<" "<<i;
					return 0;
				}
				
			} else if(i>=n&&j%2==0) {
				j++;
				i=1;
				b[i][j]=a[k];
				//cout<<b[i][j];
				if(c==b[i][j]) {
					cout<<j<<" "<<i;
					return 0;
				}
				
			}   if(j%2==1) {
				for(int o=1;o<n;o++){
					b[o][j]=a[k];
				if(c==b[o][j]) {
					cout<<j<<" "<<o;
					return 0;
				}
				
				}
				
		  } else if(j%2==0) {
				for(int p=n; p>=1; p--) {
					b[p][j]=a[k];
					//cout<<b[i][j];
					if(c==b[p][j]) {
						cout<<j<<" "<<p;
						return 0;
					}
				}
			}
			k++;
		}
}
		return 0;
	}
