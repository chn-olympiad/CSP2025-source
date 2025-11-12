#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001][4],m[4],c[100001],mx,mn,i,j,ij,cnt,ans;
unordered_map<int,int>mp;
int max(int x,int y,int z){
	return max(x,max(y,z));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=m[1]=m[2]=m[3]=0;
		cin>>n;
		for(i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(i=1;i<=n;i++){
			mx=0;
			for(j=1;j<=3;j++)
				if(a[i][j]>mx)mx=a[i][j],ij=j,c[i]=j;
			m[ij]++,ans+=a[i][c[i]];
		}
		mp[m[1]]=1,mp[m[2]]=2,mp[m[3]]=3;
		cnt=max(m[1],m[2],m[3]);
		if(cnt>n/2){
			j=mp[cnt];
			while(cnt>n/2){
				mn=2e4;
				for(i=1;i<=n;i++)
					if(a[i][j]<mn&&c[i]==j)mn=a[i][j],ij=i;
				ans-=a[ij][j],a[ij][j]=2e4+1,cnt--;
			}
		}
		cout<<ans;
	}
	return 0;
}
