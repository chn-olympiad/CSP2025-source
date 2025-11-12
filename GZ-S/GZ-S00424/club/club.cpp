//GZ-S00626 贵阳市第一中学 赵思翰 
#include<bits/stdc++.h>
using namespace std;
int t,n,a[4][100005],m[100005],mi[100005],ans,cnt[4],mm[100005],mmi[100005],mmm[100005],mmmi[100005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		memset(cnt,0,sizeof(cnt));
		memset(m,0,sizeof(m));
		memset(mi,0,sizeof(mi));
		memset(mm,0,sizeof(mm));
		memset(mmi,0,sizeof(mmi));
		memset(mmm,0,sizeof(mmm));
		memset(mmmi,0,sizeof(mmmi));
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if(a[1][i]>=a[2][i]&&a[1][i]>=a[3][i]){
				m[i]=a[1][i],mi[i]=1;
				if(a[2][i]>=a[3][i]){
					mm[i]=a[2][i],mmi[i]=2;
					mmm[i]=a[3][i],mmmi[i]=3;
				}
				else{
					mm[i]=a[3][i],mmi[i]=3;
					mmm[i]=a[2][i],mmmi[i]=2;
				}
			}
			else if(a[2][i]>=a[1][i]&&a[2][i]>=a[3][i]){
				m[i]=a[2][i],mi[i]=2;
				if(a[1][i]>=a[3][i]){
					mm[i]=a[1][i],mmi[i]=1;
					mmm[i]=a[3][i],mmmi[i]=3;
				}
				else{
					mm[i]=a[3][i],mmi[i]=3;
					mmm[i]=a[1][i],mmmi[i]=1;
				}
			}
			else{
				m[i]=a[3][i],mi[i]=3;
				if(a[2][i]>=a[1][i]){
					mm[i]=a[2][i],mmi[i]=2;
					mmm[i]=a[1][i],mmmi[i]=1;
				}
				else{
					mm[i]=a[1][i],mmi[i]=1;
					mmm[i]=a[2][i],mmmi[i]=2;
				}
			}
		}
		sort(m+1,m+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(cnt[mi[i]]<n/2){
				ans+=m[i],cnt[mi[i]]++;
			}
			else{
				if(cnt[mmi[i]<n/2]){
					ans+=mm[i],cnt[mmi[i]]++;
				}
				else{
					ans+=mmm[i],cnt[mmmi[i]]++;
				}
			}
		}
		cout<<ans;
	}
	
	return 0;
}
