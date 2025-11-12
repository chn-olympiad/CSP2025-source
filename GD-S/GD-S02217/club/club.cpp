#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int a[100005],b[100005],c[100005],M[100005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			M[i]=max(max(a[i],b[i]),c[i]);
		}
		int ans=0;
		if(M[1] > M[2]){
			if(a[1]==M[1] && a[2]==M[2]){
				ans+=a[1];
				if(b[2] > c[2]){
					ans+=b[2];
				}else{
					ans+=c[2];
				}
			}else if(b[1]==M[1] && b[2]==M[2]){
				ans+=b[1];
				if(a[2] > c[2]){
					ans+=a[2];
				}else{
					ans+=c[2];
				}
			}else if(c[1]==M[1] && c[2]==M[2]){
				ans+=c[1];
				if(a[2]>b[2]){
					ans+=a[2];
				}else{
					ans+=b[2];
				}
			}else{
				ans=M[1]+M[2];
			}	
		}else{
			if(a[1]==M[1] && a[2]==M[2]){
				ans+=a[2];
				if(b[1] > c[1]){
					ans+=b[1];
				}else{
					ans+=c[1];
				}
			}else if(b[1]==M[1] && b[2]==M[2]){
				ans+=b[2];
				if(a[1] > c[1]){
					ans+=a[1];
				}else{
					ans+=c[1];
				}
			}else if(c[1]==M[1] && c[2]==M[2]){
				ans+=c[2];
				if(a[1]>b[1]){
					ans+=a[1];
				}else{
					ans+=b[1];
				}
			}else{
				ans=M[1]+M[2];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
