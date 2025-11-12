#include<bits/stdc++.h>
using namespace std;
long a[100]={},n,m,xa,ans,c=1,r=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[0];xa=a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a,a+(n*m));
	for(int i=0;i<n*m;i++){
		if(a[i]==xa){
			ans=n*m-i;break;
		}
	}
	while(ans>0){
		if(ans>n){
			ans-=n;c++;
		}
		else{
			if(c%2==0){
				r=n-ans+1;
			}
			else{
				r=ans;
			}
			break;
		}
	}cout<<c<<" "<<r;
	return 0;
}

