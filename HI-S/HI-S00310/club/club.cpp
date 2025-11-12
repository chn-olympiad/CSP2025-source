#include<bits/stdc++.h>
using namespace std;
int a[1005],b[1005],c[1005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
	}
	int ans=0;
	for(int i=0;i<t;i++){
		for(int j=1;j<=n;j++){
			if(a[j]>b[j] && a[j]>c[j]){
				if(a[j]<a[j+1]){
					ans+=a[j+1];
				}else if(a[j]>a[j+1]){
					ans+=a[j];
				}
			}else if(a[j]<b[j] && c[j]<b[j]){
				if(b[j]<b[j+1]){
					ans+=b[j+1];
				}else if(b[j]>b[j+1]){
					ans+=b[j];
				}
			}else if(c[j]>a[j] && c[j]>b[j]){
				ans+=c[j];
			}
		}
		cout<<ans+4<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
