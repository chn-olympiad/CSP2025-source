//ACed at 14:38
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+20;
int n,a[N],b[N],c[N],v[N];
int s1,s2,s3,s[N],top;
long long ans;
int main(){
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;while(T--){
		ans=s1=s2=s3=top=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]&&a[i]>c[i]){
				s1++,v[i]=1,ans+=a[i];
			}else{if(b[i]>c[i]){
				s2++,v[i]=2,ans+=b[i];
			}else{
				s3++,v[i]=3,ans+=c[i];
			}}
		}
		if(s1>n/2){
			for(int i=1;i<=n;i++)if(v[i]==1)
				s[++top]=a[i]-max(b[i],c[i]);
			sort(s+1,s+top+1);
			for(int i=1;i<=s1-n/2;i++)
				ans-=s[i];
		}
		if(s2>n/2){
			for(int i=1;i<=n;i++)if(v[i]==2)
				s[++top]=b[i]-max(a[i],c[i]);
			sort(s+1,s+top+1);
			for(int i=1;i<=s2-n/2;i++)
				ans-=s[i];
		}
		if(s3>n/2){
			for(int i=1;i<=n;i++)if(v[i]==3)
				s[++top]=c[i]-max(a[i],b[i]);
			sort(s+1,s+top+1);
			for(int i=1;i<=s3-n/2;i++)
				ans-=s[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
