#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[1005][1005],ans=1,cc;
struct node{
	int r,c;
}m[1000005];
bool cmp(struct node n1,struct node n2){
	if(n1.c==n2.c)return n1.r>n2.r;
	else return n1.c<n2.c;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i][i]=a[i];
		if(a[i]==k){
			m[++m[0].r].r=i;
			m[m[0].r].c=i;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			s[i][j]=s[i][j-1]^a[j];
			if(s[i][j]==k){
				m[++m[0].r].r=i;
				m[m[0].r].c=j;
			}
		}
	}
	sort(m+1,m+1+m[0].r,cmp);
	cc=m[1].c;
	for(int i=2;i<=m[0].r;i++){
		if(cc<m[i].r){
			ans++;
			cc=m[i].c;
		}
	}
	printf("%d",ans);
	return 0;
}