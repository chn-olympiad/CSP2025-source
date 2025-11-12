#include<bits/stdc++.h>
using namespace std;
int n,k,a[5000010],s[2010][2010],cnt,ans;
struct csp{
	int x,y;
}b[500010];
bool cmp(csp a,csp b){
	if(a.y!=b.y) return a.y<b.y;
	return a.x>b.x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		s[i][i]=a[i];
		if(s[i][i]==k){
			b[++cnt]={i,i};
		}
		for(int j=i+1;j<=n;j++){
			s[i][j]=s[i][j-1]^a[j];
			if(s[i][j]==k){
				b[++cnt]={i,j};
			}
		}
	}
	sort(b+1,b+1+cnt,cmp);
	for(int i=1;i<=cnt;){
		int j=i+1;
		for(;b[j].x<=b[i].y&&j<=cnt;j++);
		ans++;
		i=j;
	}
	cout<<ans;
}
