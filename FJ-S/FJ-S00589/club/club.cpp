#include<bits/stdc++.h>
using namespace std;
int t,n,a1[100005],a2[100005],a3[100005],c[100005];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int s1=0,s2=0,s3=0,ans=0,m[100005]={0};
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a1[i]>=a2[i]&&a1[i]>=a3[i]) c[i]=1,s1++,ans+=a1[i];
			else if(a2[i]>=a1[i]&&a2[i]>=a3[i]) c[i]=2,s2++,ans+=a2[i];
			else if(a3[i]>=a2[i]&&a3[i]>=a1[i]) c[i]=3,s3++,ans+=a3[i];
		}
		if(s1>n/2){
			int sum=0;
			for(int i=1;i<=n;i++)
				if(c[i]==1)
					m[++sum]=a1[i]-max(a2[i],a3[i]);
			sort(m+1,m+1+sum,cmp);
			for(int i=1;i<=s1-(n/2);i++) ans-=m[i];
		}
		if(s2>n/2){
			int sum=0;
			for(int i=1;i<=n;i++)
				if(c[i]==2)
					m[++sum]=a2[i]-max(a1[i],a3[i]);
			sort(m+1,m+1+sum,cmp);
			for(int i=1;i<=s2-(n/2);i++) ans-=m[i];
		}
		if(s3>n/2){
			int sum=0;
			for(int i=1;i<=n;i++)
				if(c[i]==3)
					m[++sum]=a3[i]-max(a2[i],a1[i]);
			sort(m+1,m+1+sum,cmp);
			for(int i=1;i<=s3-(n/2);i++) ans-=m[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
