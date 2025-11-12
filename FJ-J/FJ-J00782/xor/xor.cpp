#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000010],pre[1000010],ans;
map<int,int>mmap;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	mmap[k]=1;
	for(int i=1;i<=n;i++){
		if(mmap[pre[i]]){
			ans++;
			mmap.clear();
		}
		mmap[k^pre[i]]=1;
	}
	printf("%d",ans);
	return 0;
}
