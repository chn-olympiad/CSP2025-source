//GZ-S00441 贵阳市第一中学 郑云曦 
#include<bits/stdc++.h>
using namespace std;
int t,n,a[500005],b[500005],c[500005],s=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		s=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+n+1);
		for(int i=n;i>n/2;i--){
			s+=a[i];
		}
		cout<<s;
 	}
	return 0;
}

