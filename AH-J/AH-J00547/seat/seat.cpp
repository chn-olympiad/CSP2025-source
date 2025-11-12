#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110],ans,d,sum;
bool cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	long long cnt=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		ans++;
		if(a[i]==cnt){
			if(ans%n==0){
				cout<<ans/n;
				d=ans/n;
			}else{
				cout<<ans/n+1;
				d=ans/n+1;
			}
			cout<<" ";
			if(ans%(n+1)==0){
				cout<<n;
			}else{
				if(d%2==0){
					if(sum==0){
						cout<<n-(ans%n);
					}
					if(sum==1){
						cout<<n-(ans%n)+1;
						sum=0;
					}
					sum++;
				}else{
					if(ans%n==0){
						cout<<n;
					}else{
						cout<<ans%n;
					}
				}
			}
		}
	}
	return 0;
}
