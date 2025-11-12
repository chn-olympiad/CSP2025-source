#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005],b[100005],c[100005];
int a1,b1,c1,ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		a1=b1=c1=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		
		for(int i=1;i<=n;i++){
			if(a[i]>=b[i]&&a[i]>=c[i]&&a1){
				if(a[i]+b[i+1]>b[i]+a[i+1]){
					if(a[i]+c[i+1]>c[i]+a[i+1]){
						ans=ans+a[i]+max(b[i],c[i]);
						cout<<ans<<endl;
						a1--;
					}
					else{
						ans=ans+c[i]+a[i-1];
						cout<<ans<<endl;
						a1--;
						c1--;
					}
				}
				else{
					ans=ans+b[i]+a[i-1];
					cout<<ans<<endl;
					a1--;
					b1--;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
