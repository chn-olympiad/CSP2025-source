#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,cnt,a[N],s[N],f[N];
struct node{
	int l,r;
}t[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	s[i]=s[i-1]^a[i];
	int l=0;
	cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j>l;j--)
			if((s[i]^s[j-1])==k){
				t[++cnt]={j,i};
				l=j;
				break;
			}
	for(int i=1;i<=cnt;i++){
		int l=1,r=i-1,id=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(t[mid].r<t[i].l){
				id=mid;
				l=mid+1;
			}
			else
				r=mid-1;
		}
		f[i]=max(f[i-1],f[id]+1);
	}
	cout<<f[cnt];
	return 0;
}