#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n;
int a[100005][5];
int cnt[5];
int op[100005];
int ans;
vector<int> v;
int read(){
	int num=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		num=((num<<3)+(num<<1))+ch-48; 
		ch=getchar();
	}
	return num;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		ans=0;
		memset(cnt,0,sizeof(cnt));
		n=read();
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=3;j++){
				a[i][j]=read();
			}
		}
		for(int i = 1;i<=n;i++){
			int dex=1;
			for(int j = 1;j<=3;j++){
				if(a[i][j]>=a[i][dex]){
					dex=j;
				}
			}
			op[i]=dex;
			cnt[dex]++;
			ans+=a[i][dex];
		}
		v.clear();
		for(int j = 1;j<=3;j++){
			if(cnt[j]>n/2){
				for(int i = 1;i<=n;i++){
					if(op[i]!=j){
						continue;
					}
					int minn=1000000;
					for(int k = 1;k<=3;k++){
						if(k==j){
							continue;
						}
						minn=min(minn,a[i][j]-a[i][k]);
					}
					v.push_back(minn);
				}
				sort(v.begin(),v.end());
				for(int i = 0;i<cnt[j]-n/2;i++){
					ans-=v[i];
				}
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

