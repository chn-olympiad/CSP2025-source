#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],xm,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xm=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		cnt++;
		if(a[i]==xm){
			if(cnt%n==0){
				cout<<cnt/n<<" ";
				if(cnt/n%2==0){
					cout<<1;
					return 0;
				}else{
					cout<<n;
					return 0;
				}
			}else if(cnt%n!=0){
				cout<<cnt/n+1<<" ";
				if((cnt/n+1)%2==0){
					cout<<cnt%n+(n-cnt%n);
					return 0;
				}else{
					cout<<cnt%n;
					return 0;
				}
			}
			
		}
	}
	return 0;
}

