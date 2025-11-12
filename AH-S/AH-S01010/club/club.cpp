#include<bits/stdc++.h>
using namespace std;
int T,n,a[100100][4],cnt[4],ans,m[100100],m2[100100],loss[100100];
vector<int> p;
int ch(int x){
	if(a[x][1]>a[x][2]&&a[x][1]>a[x][3]) return 1;
	else if(a[x][2]>a[x][3]) return 2;
	else return 3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(cnt,0,sizeof(cnt));
		p.clear();
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			m[i]=max(max(a[i][1],a[i][2]),a[i][3]);
			m2[i]=a[i][1]+a[i][2]+a[i][3]-m[i]-min(min(a[i][1],a[i][2]),a[i][3]);
			loss[i]=m[i]-m2[i];
			cnt[ch(i)]++;
			ans+=a[i][ch(i)];
		}
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2) for(int j=1;j<=n;j++) if(ch(j)==i) p.push_back(loss[j]);
			sort(p.begin(),p.end());
			for(int j=0;cnt[i]-j>n/2;j++) ans-=p[j];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
