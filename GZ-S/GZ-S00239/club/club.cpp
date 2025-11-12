//GZ-S00239 贵阳市第十八中学 李翼辰 
#include<bits/stdc++.h>
using namespace std;
int T; 
int a[200000+50],b[200000+50],c[200000+50];
int a1,b1,c1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int cnt=0;
		int n;cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]==0)a1++;
			if(b[i]==0)b1++;
			if(c[i]==0)c1++;
			cnt+=max(a[i],max(b[i],c[i]));
		}
		if(a1==n&&b1==n){
			int o=0;
			sort(c+1,c+1+n);
			for(int i=n;i>=(n-1)/2+2;i--){
				o+=c[i];
			}
			cout<<o<<endl;
			continue;
		}
		if(a1==n&&c1==n){
			int o=0;
			sort(b+1,b+1+n);
			for(int i=n;i>=(n-1)/2+2;i--){
				o+=b[i];
			}
			cout<<o<<endl;
			continue;
		}
		if(c1==n&&c1==n){
			int o=0;
			sort(a+1,a+1+n);
			for(int i=n;i>=(n-1)/2+2;i--){
				o+=a[i];
			}
			cout<<o<<endl;
			continue;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
