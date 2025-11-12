#include<bits/stdc++.h>
using namespace std;
int t,n,u,p,p1;
int ans[10005];
int a[10005];
int b[10005];
int c[10005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a[j]>>b[j]>>c[j];
			if(b[j]==0&&c[j]==0){
				p+=1;
			}else if(b[j]!=0&&c[j]==0){
				p1+=1;
			}
		}if(p==n){
			sort(a,a+n);
			for(int k=n;k>n/2;k--){
				ans[i]+=a[k-1];
			}
		}else{
			for(int j=0;j<n;j++){
				u=max(a[j],max(b[j],c[j]));
				ans[i]+=u;
			}
		}
	}for(int i=0;i<t;i++){
		cout<<ans[i];	
	}
	return 0;
}