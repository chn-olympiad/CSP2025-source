#include<bits/stdc++.h>
using namespace std;
int a[200010];
int xsum[200010];
int cnt=0;
struct qj{
    int l,r;
};
qj q[10000010];
qj ans[200010];
bool cmp(qj a,qj b){
  if(a.r-a.l!=b.r-b.l)return a.r-a.l>b.r-b.l;
  return a.r>b.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
      cin>>a[i];
      xsum[i]=xsum[i-1]^a[i];
	}
	int tot=0;
	for(int i=1;i<=n;i++){
      for(int j=i;j<=n;j++){
        if((xsum[j]^xsum[i-1])==k){
          q[++tot].l=i;
          q[tot].r=j;
		}
	  }
	}
	sort(q+1,q+tot+1,cmp);
	int cnt=0,tot2=0;
	for(int i=1;i<=tot;i++){
      int f=0;
//      cout<<q[i].l<<" "<<q[i].r<<endl;
      for(int j=1;j<=tot2;j++){
        if((q[i].l>=ans[j].l&&q[i].l<=ans[j].r)||(q[i].r>=ans[j].l&&q[i].r<=ans[j].r)){
		  f=1;
		  break;
		}
	  }
	  if(f)continue;
	  ans[++tot2].l=q[i].l;
	  ans[tot2].r=q[i].r;
	  cnt++;
	}
	cout<<cnt<<endl;
    return 0;
}
