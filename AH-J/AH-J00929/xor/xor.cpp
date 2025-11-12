#include<bits/stdc++.h>
using namespace std;
struct line{
	int l,r;
};
vector<line> s;
int a[500005],n,ans,cnt,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]=a[i]^a[i-1];
	}for(int i=1;i<=n;i++)
		for(int j=i;j>=1;j--)
			if((a[j-1]^a[i])==k)s.push_back({j,i});
	for(int i=0;i<s.size();i++)
		if(cnt<s[i].l)cnt=s[i].r,ans++;
	printf("%d\n",ans);
}
