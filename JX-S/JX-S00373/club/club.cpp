#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N],maxx[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	vector<int> vec;
	while(t--){
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		memset(maxx,0,sizeof maxx);
		int n;
		cin>>n;
		int ap=0,bp=0,cp=0,ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			maxx[i]=max({a[i],b[i],c[i]});
			if(maxx[i]==a[i]){
				ap++;
			}else if(maxx[i]==b[i]){
				bp++;
			}else{
				cp++;
			}
			ans+=maxx[i];
		}
		while(ap>n/2||bp>n/2||cp>n/2){
			if(ap>n/2){
				int maxn=-0x3f,flag=0;
				for(int i=1;i<=n;i++){
					if(maxx[i]==a[i]&&maxn<max(c[i],b[i])-a[i]&&b[i]>c[i]){
						maxn=b[i]-a[i];
						flag=2;
					}else if(maxx[i]==a[i]&&maxn<max(c[i],b[i])-a[i]){
						maxn=c[i]-a[i];
						flag=3;
					}
				}
				ap--;
				if(flag==2&&bp+1<=n/2){
					bp++;
					ans=ans+maxn;
				}
				if(flag==3&&cp+1<=n/2){
					cp++;
					ans=ans+maxn;
				}
			}
			else if(bp>n/2){
				int maxn=-0x3f,flag=0;
				for(int i=1;i<=n;i++){
					if(maxx[i]==b[i]&&maxn<max(c[i],a[i])-b[i]&&a[i]>c[i]){
						maxn=a[i]-b[i];
						flag=2;
					}else if(maxx[i]==b[i]&&maxn<max(c[i],a[i])-b[i]){
						maxn=c[i]-b[i];
						flag=3;
					}
				}
				bp--;
				if(flag==2&&ap+1<=n/2){
					ap++;
					ans=ans+maxn;
				}
				if(flag==3&&cp+1<=n/2){
					cp++;
					ans=ans+maxn;
				}
			}
			else if(cp>n/2){
				int maxn=-0x3f,flag=0;
				for(int i=1;i<=n;i++){
					if(maxx[i]==c[i]&&maxn<max(a[i],b[i])-c[i]&&a[i]>b[i]){
						maxn=a[i]-c[i];
						flag=2;
					}else if(maxx[i]==c[i]&&maxn<max(a[i],b[i])-c[i]){
						maxn=b[i]-c[i];
						flag=3;
					}
				}
				cp--;
				if(flag==2&&ap+1<=n/2){
					ap++;
					ans+=maxn;
				}
				if(flag==3&&bp+1<=n/2){
					bp++;
					ans+=maxn;
				}
			}
		}
		vec.push_back(ans);
	}
	for(auto x:vec){
		cout<<x<<'\n';
	}
	return 0;
}
