#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int a[N];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b=1,c=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	for(int i=2;i<=n*m;i++){
		if(a[1]<a[i]){
			if(c==1&&b%2==0){
				b++;
				continue;
			}
			if(c==m&&b%2==1){
				b++;
				continue;
			}
			if(b%2==1)c++;
			if(b%2==0)c--;
		}
	}
	cout<<b<<" "<<c;
	return 0;
}

