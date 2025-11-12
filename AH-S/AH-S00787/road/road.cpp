#include<bits/stdc++.h>
using namespace std;
struct lu {
	long long to,en,mo;
}rd[2000009];
long long fa[2000009],ans;
bool cmp(lu ax,lu bx){
	return ax.mo<bx.mo;
}
long long rt(long long x){
	if(fa[x]==x)return x;
	return fa[x]=rt(fa[x]);
}
void ji(long long x,long long y){
	x=rt(x),y=rt(y);
	fa[x]=y;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>rd[i].to>>rd[i].en>>rd[i].mo;
		fa[i]=i;
	}
	for(int i=1;i<=k;i++){
		long long ufi;
		cin>>ufi;
		for(int j=1;j<=n;j++){
			m++;
			rd[m].to=n+i;
			rd[m].en=j;
			cin>>rd[m].mo;
		}
	}
	sort(rd+1,rd+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(rt(rd[i].to)==rt(rd[i].en))continue;
		ji(rd[i].to,rd[i].en);
		ans+=rd[i].mo;
	}
	cout<<ans;
	return 0;
}
