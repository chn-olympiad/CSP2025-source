#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],r,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=m;i++){
		s+=n;
		if(a[s]>=r)
			for(int j=s-n+1;j<=s;j++)
				if(a[j]==r){
					if(i%2){
						cout<<n-s+j<<" "<<i;
						return 0;
					}
					else{
						cout<<s-j<<" "<<i;
						return 0;
					}
				}
	}
}
