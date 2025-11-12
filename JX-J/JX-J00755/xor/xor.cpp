#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1000,M=1e3+1000;
int n,k,a[N],f,cnt1,cnt0,b[M][M],cnt,ans=1,xx,yy;
int ff[M][M];
struct stu{
	int x,y;
}c[6000000];
bool inrange(stu xx,stu yy){
	if(xx.x<=yy.x&&xx.y>=yy.y)return 1;
	return 0;
}
bool cmp(stu xx,stu yy){
	if(inrange(xx,yy)||inrange(yy,xx))return xx.x>yy.x;
	return xx.x<yy.x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i][i]=a[i];
		if(a[i]==k){
			c[++cnt].x=i;
			c[cnt].y=i;
		}//ff[i][i]=1;
		if(a[i]!=1)f=1;
		if(a[i]==0)cnt0++;
		if(a[i]==1)cnt1++;
	}
	if(f==0&&k==0){
		cout<<n/2;
		return 0;
	}
	if(cnt0+cnt1==n){
		if(k==1)cout<<cnt1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int xx=a[i];
		for(int j=i+1;j<=n;j++){
			xx^=a[j];
			b[i][j]=xx;
			if(xx==k){
				c[++cnt].x=i;
				c[cnt].y=j;
			}
		}
	}
	//sort(c+1,c+cnt+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ff[i][j]=ff[i][j-1];
			for(int kk=i;kk<=j;kk++){
				if(b[kk][j]==k){
					ff[i][j]=max(ff[i][j],ff[i][kk-1]+1);
				}
				
			}
		}
	}
	/*int bh=1;
	xx=c[bh].x;
	yy=c[bh].y;
	while(bh<=cnt){
		
		for(bh=bh+1;bh<=cnt;bh++){
			if(c[bh].x>yy){
				xx=c[bh].x;
				yy=c[bh].y;
				break;
			}
		}
		//if(bbh!=bh)ans++;
	}
	cout<<ans;*/
	cout<<ff[1][n];
	return 0;
}
