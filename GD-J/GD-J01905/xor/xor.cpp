#include<bits/stdc++.h>
using namespace std;
int n,a[500005],m,b[500005],s,l,k;
unordered_map<int,int>mp;
struct ab{
	int x,y;
}h[500005];
bool cmp(ab x,ab y){
	return x.y<y.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=(b[i-1]^a[i]);
		if(mp[b[i]^m]&&i>1) h[++k].y=i,h[k].x=mp[b[i]^m]+1;
		if(b[i]==m) h[++k].x=1,h[k].y=i;
		if(a[i]==m) h[++k].x=i,h[k].y=i;
		mp[b[i]]=i;
	}
	sort(h+1,h+1+k,cmp);
	for(int i=1;i<=k;i++){
		if(h[i].x>l) l=h[i].y,s++;
	}
	cout<<s;
	return 0;
}
