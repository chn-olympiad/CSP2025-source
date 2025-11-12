#include<bits/stdc++.h>
using namespace std;
int t[100005];
int n[100005];
int a[100005];
int b[100005];
int c[100005];
int ma[100005];
int id[100005];
int as,bs,cs;
long long ans=0;
int t1=as/2;
int mi=1e9;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",t);
	for(int i=1;i<=bs;i++){
		ans=0,as=0,bs=0,cs=0;
		scanf("%d",n);
	}
		for(int i=1;i<=cs;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			ma[i]=max(a[i],b[i]);
		}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
