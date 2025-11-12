#include<bits/stdc++.h>
using namespace std;
#define filename "club"
const int N=1e5+2;
int T,n,a[N][3],ans,cnt[3],b[N],t[N];
vector<int> c;

int maxa(int i){
	int res=0;
	if(a[i][res]<a[i][1]) res=1;
	if(a[i][res]<a[i][2]) res=2;
	return res;
}

int mina(int i){
	int res=0;
	if(a[i][res]>=a[i][1]) res=1;
	if(a[i][res]>=a[i][2]) res=2;
	return res;
}

int mida(int i){
	return 3-maxa(i)-mina(i);
}

int main(){
#ifdef filename
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		ans=cnt[0]=cnt[1]=cnt[2]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j:{0,1,2}) scanf("%d",&a[i][j]);
			b[i]=maxa(i);
			cnt[b[i]]++;
			t[i]=a[i][b[i]]-a[i][mida(i)];
			ans+=a[i][b[i]];
		}
		int idx=114514;
		for(int i:{0,1,2}) if(cnt[i]>(n>>1)){
			idx=i;
			break;
		}
		if(idx!=114514){
			c.clear();
			for(int i=1;i<=n;i++) if(b[i]==idx) c.emplace_back(t[i]);
			sort(c.begin(),c.end());
			for(int x:c){
				ans-=x;
				cnt[idx]--;
				if(cnt[idx]<=(n>>1)) break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}