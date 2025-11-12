#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],num;
	cin>>n>>m;
	int x=n*m;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+x+1);
	int sum=1;
	for(int i=x;i>=1;i--){
		if(a[i]==num){
			if(sum%n!=0){
				cout<<sum/n+1<<" ";
				if((sum/n+1)%2==0){
					cout<<n-sum%n+1;
				}
				else{
					cout<<sum%n;
				}
				break;
			}
			else{
				cout<<sum/n<<" ";
				if((sum/n)%2==0){
					cout<<1;
				}
				else{
					cout<<n;
				}
				break;
			}
		}
		sum++;
	}
	return 0;
} 
