#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[110];
int xm,num=0;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xm=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		num++;
		if(a[i]==xm){
			break;
		}
	}
	if(num<=n){
		cout<<1<<" "<<num<<endl;
	}else{
		if(num%n!=0){
			if((num/n+1)%2==0){
				cout<<num/n+1<<" "<<n-num%n+1<<endl;
			}else{
				cout<<num/n+1<<" "<<num%n<<endl;
			}
		}else{
			if((num/n+1)%2==0){
				cout<<num/n<<" "<<n-num%n+1<<endl;
			}else{
				cout<<num/n<<" "<<num%n<<endl;
			}
		}
	}
	return 0;
}
