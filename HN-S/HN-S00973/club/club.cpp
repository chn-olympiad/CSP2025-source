#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],c[100010];
struct st{
	int x,y;
} p[100010];
bool cmp1(st A,st B){
	return A.x<B.x;
}
bool cmp2(st A,st B){
	return A.y<B.y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		long long n,ans=0;
		cin >> n;
		int o=0,p=0;
		for(int i=0;i<n;i++){
			cin >> a[i] >> b[i] >> c[i];
			p[i].x=a[i];
			p[i].y=b[i];
			if(b[i]!=0) o=1;
			if(c[i]!=0) p=1;
		}
		if(o==0&&p==0){
			sort(a,a+n);
			for(int i=n-1;i>=n/2;i--) ans+=a[i];
		}
		else if(o!=0&&p==0){
			long long num=0,cnt=0,vis=0;
			for(int i=0;i<n;i++){
				if(a[i]>b[i]) num++;
				else if(a[i]==b[i]) vis++;
				else cnt++;
				ans+=max(a[i],b[i]);
			}
			if(num<=n/2&&cnt<=n/2){
				ans=ans;
			}
			else if(num>n/2){
				sort(p,p+n,cmp1);
				int k=num-n/2,jkl=0;
				for(int i=0;i<n&&jkl<k;i++){
					if(p[i].y>p[i].x) continue;
					else{
						jkl++;
						ans-=p[i].x;
						ans+=p[i].y;
					}
				}
			}
			else if(cnt>n/2){
				sort(p,p+n,cmp2);
				int x=num-n/2,jkl=0;
				for(int i=0;i<n&&jkl<x;i++){
					if(p[i].x>p[i].y) continue;
					else{
						jkl++;
						ans-=p[i].y;
						ans+=p[i].x;
					}
				}
			}
			else{
				ans=ans;
			}
		}
		else ans=1313113;
		cout << ans << endl;
	}
	return 0; 
} 
