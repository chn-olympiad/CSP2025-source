#include<bits/stdc++.h>
using namespace std;
struct club{
	int c1,c2,c3,vis=0;
}a[100241];
int t,n,ans,c,s1,s2,s3;
bool cmp1(club bzo,club bze){
	return bzo.c1>bze.c1;
}
bool cmp2(club bzo,club bze){
	return bzo.c2>bze.c2;
}
bool cmp3(club bzo,club bze){
	return bzo.c3>bze.c3;
}
void dfs(int i,int s1,int s2,int s3){
	if(s1>n/2||s2>n/2||s3>n/2){return;}
	if(i>n){ans=max(c,ans);return;}
	c+=a[i].c1;
	dfs(i+1,s1+1,s2,s3);
	c=c-a[i].c1+a[i].c2;
	dfs(i+1,s1,s2+1,s3);
	c=c-a[i].c2+a[i].c3;
	dfs(i+1,s1,s2,s3+1);
	c-=a[i].c3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		s1=0,s2=0,s3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
			if(a[i].c1==0)s1++;
			if(a[i].c2==0)s2++;
			if(a[i].c3==0)s3++;
		}
		if(n==2){
			ans=max(max(a[1].c1+max(a[2].c2,a[2].c3),a[1].c2+max(a[2].c1,a[2].c3)),a[1].c3+max(a[2].c1,a[2].c2));
			cout<<ans<<endl;
			continue;
		}
		if(s2==n&&s3==n){
			sort(a+1,a+n+1,cmp1);
			ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=a[i].c1;
			}
			cout<<ans<<endl;
			continue;
		}
		if(s1==n&&s3==n){
			sort(a+1,a+n+1,cmp2);
			ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=a[i].c2;
			}
			cout<<ans<<endl;
			continue;
		}
		if(s1==n&&s2==n){
			sort(a+1,a+n+1,cmp3);
			ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=a[i].c3;
			}
			cout<<ans<<endl;
			continue;
		}
		if(n>18){
			s1=0,s2=0,s3=0;
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				s1+=a[i].c1;
			}
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n/2;i++){
				s2+=a[i].c2;
			}
			sort(a+1,a+n+1,cmp3);
			for(int i=1;i<=n/2;i++){
				s3+=a[i].c3;
			}
			ans=max(max(s1,s2),s3);
		}
		ans=-1;
		dfs(1,0,0,0);
		cout<<ans<<endl;
		continue;
	}
	return 0;
}
