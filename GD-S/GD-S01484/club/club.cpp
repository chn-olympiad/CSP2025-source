#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int BUF=1<<20;
char buf[BUF],*p1=buf,*p2=buf;
inline char gc(){
	if(p1==p2)p2=(p1=buf)+fread(buf,1,BUF,stdin);
	return p1==p2?EOF:*p1++;
}
template<class T=int>T read(T&&x=0){
	int f=1;
	x=0;
	char ch=gc();
	while(!isdigit(ch))f-=(ch=='-')<<1,ch=gc();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=gc();
	return x;
}
const int N=1e5+5;
int a[N][4],fid[N],sid[N],dt[N];
int sum[4],cnt[4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while(t--){
		int n=read();
		for(int i=1;i<=3;i++)sum[i]=cnt[i]=0;
		for(int i=1;i<=n;i++){
			fid[i]=sid[i]=dt[i]=0;
			for(int j=1;j<=3;j++){
				read(a[i][j]);
				if(a[i][j]>=a[i][fid[i]])sid[i]=fid[i],fid[i]=j;
				else if(a[i][j]>=a[i][sid[i]])sid[i]=j;
			}
			cnt[fid[i]]++;
			sum[fid[i]]+=a[i][fid[i]];
			dt[i]=a[i][fid[i]]-a[i][sid[i]];
		}
		int ans=sum[1]+sum[2]+sum[3];
		for(int i=1;i<=3;i++)if(cnt[i]>n/2){
			vector<int>res;
			for(int j=1;j<=n;j++)if(fid[j]==i)res.push_back(j);
			sort(res.begin(),res.end(),[&](int x,int y){
				return dt[x]<dt[y];
			});
			int tmp=cnt[i]-n/2;
			for(int i=0;i<tmp;i++)ans-=dt[res[i]];
			break;
		}
		cout<<ans<<endl;
	} 
}
