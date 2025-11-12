#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n*m];
    for(int i=0;i<n*m;i++){
		cin>>a[i];
		}
    long long sum=0;
    for(int i=1;i<n*m;i++){
		if(a[i]>a[0]){
			sum++;
			}
		}
	long long an,am;
	if(sum%n==0){
		am=sum/n+1;
		if(sum/n%2==0){
			an=1;
			}
		else{
			an=n;
			}
		}
	else{
		am=sum/n+1;
		if(sum/n%2==0){
			an=sum%n+1;
			}
		else{
			an=n-sum%n;
			}
		}
	
	cout<<am<<" "<<an;
    
    return 0;
}
