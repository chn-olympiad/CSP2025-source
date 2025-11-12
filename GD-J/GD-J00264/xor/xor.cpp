#include<iostream>
using namespace std;
const int si=1e6+10;
int n,k,a[si],t[si],l=1,val=0,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		val^=a[i];
		if(l<=t[k^val]||val==k)
			l=i+1,val=0,++ans;
		t[val]=l;
	}printf("%d",ans);
	return 0;
}
