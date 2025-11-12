#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int t,n,s[4],a[N][4],b[N],c[N],top,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		top=ans=0;
		s[1]=s[2]=s[3]=0;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			int s3=-1e9;
			for(int j=1;j<=3;j++)
				if(a[i][j]>=s3){
					s3=a[i][j];
					c[i]=j;}
			s[c[i]]++;
			ans+=a[i][c[i]];}
		int s1=-1e9,s2;
		for(int j=1;j<=3;j++)
			if(s[j]>=s1){
				s1=s[j];
				s2=j;}
		if(s1<=n/2){
			cout<<ans<<endl;
			continue;}
		for(int i=1;i<=n;i++){
			if(c[i]!=s2)
				continue;
			b[++top]=a[i][c[i]];
			int s3=-1e9;
			for(int j=1;j<=3;j++)
				if(j!=c[i])
					s3=max(s3,a[i][j]);
			b[top]-=s3;}
		sort(b+1,b+top+1);
		for(int i=1;i<=s1-n/2;i++)
			ans-=b[i];
		cout<<ans<<endl;
	}
	return 0;
}
