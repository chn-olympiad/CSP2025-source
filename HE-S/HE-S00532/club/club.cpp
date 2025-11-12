#include<bits/stdc++.h>
using namespace std;
int t[4];int a[101010],b[101010],c[101010];int s[101010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		long long ans=0;
		t[1]=t[2]=t[3]=0;
		int n;
		cin>>n;
		
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]&&a[i]>c[i]){
				t[1]++;
			}else if(b[i]>a[i]&&b[i]>c[i]){
				t[2]++;
			}else t[3]++;
		}
		int cnt=0;
		if(t[1]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i]>b[i]&&a[i]>c[i]){
					ans+=a[i];
					s[++cnt]=a[i]-max(b[i],c[i]);
				}else {
					ans+=max(b[i],c[i]);
				}
			}
			sort(s+1,s+cnt+1);
			for(int i=1;i<=t[1]-n/2;i++)ans-=s[i];
				
		}else if(t[2]>n/2){
			for(int i=1;i<=n;i++){
				if(b[i]>a[i]&&b[i]>c[i]){
					ans+=b[i];
					s[++cnt]=b[i]-max(a[i],c[i]);
				}else {
					ans+=max(a[i],c[i]);
				}
				
			}
			sort(s+1,s+cnt+1);
			for(int i=1;i<=t[2]-n/2;i++)ans-=s[i];	
		}else if(t[3]>n/2){
			for(int i=1;i<=n;i++){
				if(c[i]>b[i]&&c[i]>a[i]){
					s[++cnt]=c[i]-max(b[i],a[i]);
					ans+=c[i];
				}else ans+=max(a[i],b[i]);
			}
			sort(s+1,s+cnt+1);
			for(int i=1;i<=t[3]-n/2;i++)ans-=s[i];	
		}else {
			for(int i=1;i<=n;i++)
				ans+=max(a[i],max(b[i],c[i]));
		}
		cout<<ans<<'\n';
	}
	return 0;
}
