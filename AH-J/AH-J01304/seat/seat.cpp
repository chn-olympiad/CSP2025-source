#include<bits/stdc++.h>
using namespace std;
long long x,y,f,n,m;
long long a[110];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			f=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(long long i=1;i<=n*m;i++){
		//cout<<'*'<<a[i]<<endl;
		if(a[i]==f){
			//cout<<i<<' ';
			x=i/n;
			if(i%n!=0){
				x++;
			}
			if(x%2==0){
				y=(n+1)-i%n;
			}
			else{
				y=i%n;
				if(y==0){
					y=n;
				}
			}
			cout<<x<<' '<<y;
			return 0;
		}
	}
}
