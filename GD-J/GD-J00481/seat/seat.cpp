#include<bits/stdc++.h>
using namespace std;
int a[105];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(r==a[i]){
			int flag=0;
			if(i%n!=0){
				flag=1;
			}else{
				flag=0;
			}
			if(flag){
				cout<<i/n+1<<' ';
			    if((i/n+1)%2==0){
			    	cout<<n-i%n+1;
				}else{
					cout<<i%n;
				}
			}else{
				cout<<i/n<<' ';
				if((i/n)%2==0){
			    	cout<<1;
				}else{
					cout<<n;
				}
			}
			return 0;		
		}
	}
	return 0;
}

