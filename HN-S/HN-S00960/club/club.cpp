#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,id,val,cho;
}a1[100010];
int T,n,ans;

bool cmp1(node x1,node x2){
	if((x1.a-x1.b)==(x2.a-x2.b))return (x1.c-min(x1.b,x1.a))>(x2.c-min(x2.b,x2.a));
	return (x1.a-x1.b)>(x2.a-x2.b);
}
bool cmp2(node x1,node x2){
	return x1.val>x1.val;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		for(int i=1;i<=n;i++)a1[i].a=a1[i].b=a1[i].c=a1[i].cho=a1[i].id=a1[i].val=0;
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			cin>>a1[i].a>>a1[i].b>>a1[i].c;
			a1[i].id=i;
		}
		sort(a1+1,a1+1+n,cmp1);
		for(int i=1;i<=n;i++){
			if(i<=n/2){
				a1[i].cho=1;
				a1[i].val=a1[i].c-a1[i].a;
			}
			else{
				a1[i].cho=2;
				a1[i].val=a1[i].c-a1[i].b;
			}
		}
		sort(a1+1,a1+1+n,cmp2);
		int num=0;
		for(int i=1;i<=n;i++){
			if(a1[i].val>0&&num<=n/2)ans+=a1[i].c;
			else{
				if(a1[i].cho==1)ans+=a1[i].a;
				else ans+=a1[i].b;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

