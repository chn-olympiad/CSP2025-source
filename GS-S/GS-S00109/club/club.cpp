#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout);
	int t;
	int n;
	int a[1000],b[1000],c[1000];
	int a1,b1,c1;
	int ans=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		a1=n/2;
		b1=n/2;
		c1=n/2;
		ans=0;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
			//cout<<a1<<" "<<ans;
			if(a1==0){
				ans=max(ans+max(b[j],c[j]),ans-a[j-1]+max(b[j-1],c[j-1])+a[j]);
				
			}else if(b1==0){
				ans=max(ans+max(a[j],c[j]),ans-b[j-1]+max(a[j-1],c[j-1])+b[j]);
			}else if(c1==0){
				ans=max(ans+max(b[j],a[j]),ans-c[j-1]+max(b[j-1],a[j-1])+c[j]);
			}else{
				ans+=max(a[j],max(b[j],c[j]));
				if(a[j]>max(b[j],c[j])){
					a1-=1;
				}else if(b[j]>max(a[j],c[j])){
					b1-=1;
				}else{
					c1-=1;
				}
			}
			
			}
			cout<<ans<<endl;
		}
		return 0;
	}

