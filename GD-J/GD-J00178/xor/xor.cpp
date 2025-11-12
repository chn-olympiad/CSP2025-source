#include <bits/stdc++.h>
using namespace std;
int n,k,cnt,a[500005],s[500005],skip[500005];
struct data{
	int l,r;
	bool operator<(data b) const{
		return r<b.r or (l==b.l or r==b.r) and r-l<b.r-b.l; 
	} 
}s2[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	s[1]=a[1];
	for(int i=2;i<=n;i++) s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			if(s[i]-s[j]==k){
				s2[i].l=j,s2[i].r=i;
			}
	sort(s2+1,s2+n+1);
	for(int i=1;i<=n;i++){
		if(s2[i+1].r>s2[i+2].l or s2[i+1].l<s2[i].r) {
			skip[i]=i+1;
		}
	}
	for(int i=1;i<=n;i++){
		if(!i==skip[i]) cnt++;
	}
	cout<<cnt;
	return 0;
}
