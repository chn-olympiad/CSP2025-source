#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int check(int t1,int t2,int t3,int temp){
	if(temp==t1) return 1;
	if(temp==t2) return 2;
	return 3;
}
int maxq(int a,int b,int c){
	int maxn=max(a,b);
	maxn=max(maxn,c);
	return maxn;
}
int minq(int a,int b,int c){
	int minn=min(a,b);
	minn=min(minn,c);
	return minn;
}
int check1(int n,int *t1,int *t2){
	int sum[4]={0};
	for(int i=1;i<=n;i++){
		sum[t1[i]]++;
		if(sum[t1[i]]>n/2) {
			//cout<<t1[i]<<endl;
			return t1[i];
		}
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int a=1;a<=t;a++){
		int n,c1[N],c2[N],c3[N],t1[N],t2[N],club[4]={0},mint=11451411,ans=0,minplace=1;
		bool flag[N];
		memset(flag,false,sizeof flag);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>c1[i]>>c2[i]>>c3[i];
			int maxn=max(c1[i],c2[i]),minn=min(c1[i],c2[i]);
			maxn=max(maxn,c3[i]);minn=min(minn,c3[i]);
			int midd=c1[i]+c2[i]+c3[i]-maxn-minn;
			t1[i]=check(c1[i],c2[i],c3[i],maxn);
			t2[i]=check(c1[i],c2[i],c3[i],midd);
			
			//cout<<t1[i]<<" "<<t2[i]<<endl;
		}
		for(int i=1;i<=n;i++){
			if(t1[i]!=check1(n,t1,t2)) flag[i]=true;
			int maxn=maxq(c1[i],c2[i],c3[i]),minn=minq(c1[i],c2[i],c3[i]);
			int midd=c1[i]+c2[i]+c3[i]-maxn-minn,w=check1(n,t1,t2);
			if(mint>maxn-midd&&(t1[i]==w||w==0)){
				minplace=i;
			}
			if(t1[i]==w||w==0){
				mint=min(mint,maxn-midd);
			}
			//cout<<mint<<endl;
			if(club[t1[i]]==n/2){
				//cout<<mint<<endl;
				if(maxn-midd>mint){
					ans+=maxn-mint;
					flag[minplace]=true;
					//cout<<i<<" "<<minplace<<endl;
					minplace=1;
					mint=1e9;
					for(int j=1;j<=i;j++){
						if(flag[j]) continue;
						int t=maxq(c1[j],c2[j],c3[j]),mid=c1[j]+c2[j]+c3[j]-maxq(c1[j],c2[j],c3[j])-minq(c1[j],c2[j],c3[j]);
						if(mint>t-mid) minplace=j;
						mint=min(mint,t-mid);
						
					}
					//cout<<mint<<" "<<minplace<<endl;
				}
				else{
					ans+=(c1[i]+c2[i]+c3[i]-minn-maxn);
					flag[i]=true;
					minplace=1;
					mint=1e9;
					for(int j=1;j<=i;j++){
						if(flag[j]) continue;
						int t=maxq(c1[j],c2[j],c3[j]),mid=c1[j]+c2[j]+c3[j]-maxq(c1[j],c2[j],c3[j])-minq(c1[j],c2[j],c3[j]);
						if(mint>t-mid) minplace=j;
						mint=min(mint,t-mid);
						
					}
				}
			}
			else{
				club[t1[i]]++;
				ans+=maxn;
			}
			
		    //cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
	
