#include<bits/stdc++.h>
using namespace std;
int s[555555],ii=1;
struct node{
    int l,r;
}q[555555];
bool cmp(node a,node b){
    return a.l<=b.l;
}
int main () {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[555555];
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    s[1]=a[1];
    for(int i=2;i<=n;i++){
        s[i]=s[i-1]^a[i];
    }
    int t=n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=t;j++){
            int u=s[i+j-1]^s[j-1];
            if(u==k) q[ii].l=j,q[ii++].r=i+j-1;
        }
        t--;
    }
    sort(q+1,q+ii,cmp);
    node z=q[1];
    int r=1;
    for(int i=2;i<ii;i++){
        if(z.r<q[i].l){
           r++;
           z=q[i]; 
        }else if(z.r>q[i].l&&z.r>q[i].r) z=q[i];
    }
    printf("%d",r);
	return 0;
}
