#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const int M=1e6+10;
int a[N][N],n,m,b[M],R,cnt=1,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
		if(i==1) R=b[i];
	}
	sort(b+1,b+1+n*m,greater<int>());
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[j][i]=b[cnt];
				cnt++;
				if(a[j][i]==R) c=i,r=j;
			}
		}else{
			for(int j=n;j>=1;j--){
				a[j][i]=b[cnt];
				cnt++;
				if(a[j][i]==R) c=i,r=j;
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
