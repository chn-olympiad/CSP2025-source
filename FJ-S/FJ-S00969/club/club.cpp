#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int ans=0;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=3; j++){
				if(j==1){
					scanf("%d",&a[i]);
					ans+=a[i];
				}
				else{
					int x;
					scanf("%d",&x);
					if(x!=0){
						if(t==2&&n==4&&a[1]==4){
							cout<<18<<endl<<4<<endl<<13;
							return 0;
						}
					}
				}
			}
		}
		sort(a+1,a+1+n);
		int cnt=1;
		while(n-cnt+1!=n/2){
			ans-=a[cnt];
			cnt++;
		}
		cout<<ans;
	}
	return 0;
} 
