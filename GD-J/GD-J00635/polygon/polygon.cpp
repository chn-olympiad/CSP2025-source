#include<bits/stdc++.h>
using namespace std;
long long n,l,r,mid,s=1,k=1,ans=0,a[5005];
void f(int x,int R,int sum){
	for(int L=x;L<=R-2;L++){
		if(sum+a[L]+a[R-1]>a[R]){
			l=L;
			r=R-1;
			while(l+1<r){
				mid=(l+r)/2;
				if(sum+a[L]+a[mid]<=a[R]){
					l=mid;
				}
				else{
					r=mid;
				}
			}
			ans=(ans+R-r)%998244353;
		}
		if(R-L>=3){
			f(L+1,R,sum+a[L]);
		}
		else{
			return;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=2;i<n;i++){
		f(0,i,0);
	}
	cout<<ans<<endl;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
