#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,a[100000],s,b[100000],c=0,r=0;
	int q=0;
	cin>>n>>m;
	if(n==1&&m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	s=a[0];
	for(int i=101;i>0;i--){
		for(int j=0;j<n*m;j++){
			if(a[j]==i){
				b[c]=i;	
				c++;
				break;
				}
		}
	}
	if(a[0]>a[1]&&a[0]>a[2]&&a[0]>a[3]){
		cout<<1<<" "<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[r]==s&&i%2==0){
				cout<<j+1<<" "<<i;
				q++;
			}
			if(b[r]==s&&i%2==1){
				cout<<n-j+1<<" "<<n-i+1;
				q++;
			}
			r++;
		}
	}
		return 0;
} 
