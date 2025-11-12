#include<bits/stdc++.h> 
using namespace std;
int t,n,ans=0,q[60],h[60],ww[60];
int a[10005][3];
struct node{
	int id,g;
}b[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0; 
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				q[i]=max(a[i][1],a[i][2]);
				h[i]=max(a[i][2],a[i][3]);
				ww[i]=min(q[i],h[i]);
				b[i].g=max(max(a[i][j-1],a[i][j]),b[i].g);
				if(b[i].g>q[i] || b[i].g>h[i])
					b[i].id=j;
			}
		}
		if(n==2){
			if(b[1].id != b[2].id)
				ans=b[1].g+b[2].g;
			else{
				ans=max(b[1].g+ww[2],b[2].g+ww[1])+1;
			}
		}
		else{
			for(int i=1;i<=n;i=i+2){
				ans+=b[i].g;
			}
			ans=ans/2;
		} 
		cout<<ans;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j]=0;
				b[i].g=0;
				b[i].id=0;
				q[i]=0;
				h[i]=0;
				ww[i]=0;
			}
		}
	} 
	return 0;
}
