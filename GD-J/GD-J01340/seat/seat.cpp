#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int c[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	for(int i=1;i<n*m;i++){
		cin>>c[i];
	}
	sort(c+1,c+n*m,cmp);
	for(int i=1;i<n*m;i++){
		if(x>c[i]){
			int t=(i+n-1)/n;
			cout<<t<<" ";
			if(t%2==1){
				if(i%n==0) cout<<n;
				else cout<<i%n;
			}
			else {
				if(i%n==0) cout<<1;
				else cout<<n-i%n+1;
			}
			return 0;
		}
	}
	cout<<n<<" "<<m;
	return 0;
}
