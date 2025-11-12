#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,sum,cl,c1,c2,mc;
}a[100005];
int cmp(node x,node y){
	return x.mc<y.mc;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,ans=0,sua=0,sub=0,suc=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i].a>>a[i].b>>a[i].c,a[i].sum=a[i].a+a[i].b+a[i].c,ans+=max(a[i].a,max(a[i].b,a[i].c));
		for(int i=1;i<=n;i++){
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c)
				a[i].cl=1,sua++,a[i].c1=a[i].a-a[i].b,a[i].c2=a[i].a-a[i].c,a[i].mc=min(a[i].c1,a[i].c2);
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c)
				a[i].cl=2,sub++,a[i].c1=a[i].b-a[i].a,a[i].c2=a[i].b-a[i].c,a[i].mc=min(a[i].c1,a[i].c2);
			else
				a[i].cl=3,suc++,a[i].c1=a[i].c-a[i].a,a[i].c2=a[i].c-a[i].b,a[i].mc=min(a[i].c1,a[i].c2);
		}
		sort(a+1,a+1+n,cmp);
		if(sua>n/2){
			for(int i=1;i<=n&&sua>n/2;i++){
				if(a[i].cl==1)
					ans-=a[i].mc,sua--;
			}
		}
		else if(sub>n/2){
			for(int i=1;i<=n&&sub>n/2;i++){
				if(a[i].cl==2)
					ans-=a[i].mc,sub--;
			}
		}
		else if(suc>n/2){
			for(int i=1;i<=n&&suc>n/2;i++){
				if(a[i].cl==3)
					ans-=a[i].mc,suc--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
