#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int m, id;
}a[100005], b[100005], c[100005];
int comp(node x, node y){
	return x.m>y.m;
}
int a2, b2, c2, ans, maxn;
void test(){
	cin>>n;
	a2=0, b2=0, c2=0, ans=0, maxn=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].m>>b[i].m>>c[i].m;
		a[i].id=i; b[i].id=i; c[i].id=i;
	}
	sort(a+1,a+1+n,comp);
	sort(b+1,b+1+n,comp);
	sort(c+1,c+1+n,comp);
	for(int i=1;i<=n/2;i++){
		a2+=a[i].m;
		b2+=b[i].m;
		c2+=c[i].m;
	}
	maxn=max(a2,max(b2,c2));
	ans+=maxn;
	if(a2==maxn){
		int num=n/2, num2=n/2;
		bool flag=0, fa=0;
		for(int i=1;i<=n/2;i++){
			for(int j=1;j<=n/2;j++){
				if(a[i].id==b[j].id&&flag==0){
					b2-=b[j].m;
					num++;
					b2+=b[num].m;
					flag=1;
				}
				if(a[i].id==c[j].id&&fa==0){
					c2-=c[j].m;
					num2++;
					c2+=c[num2].m;
					fa=1;
				}
				if(flag==1&&fa==1) break;
			}
		}
		maxn=0;
		maxn=max(b2,c2);
		ans+=maxn;
	}
	else if(b2==maxn){
		int num=n/2, num2=n/2;
		bool flag=0, fa=0;
		for(int i=1;i<=n/2;i++){
			for(int j=1;j<=n/2;j++){
				if(a[j].id==b[i].id&&flag==0){
					a2-=a[j].m;
					num++;
					a2+=a[num].m;
					flag=1;
				}
				if(b[i].id==c[j].id&&fa==0){
					c2-=c[j].m;
					num2++;
					c2+=c[num2].m;
					fa=1;
				}
				if(flag==1&&fa==1) break;
			}
		}
		maxn=0;
		maxn=max(a2,c2);
		ans+=maxn;
	}
	else if(c2==maxn){
		int num=n/2, num2=n/2;
		bool flag=0, fa=0;
		for(int i=1;i<=n/2;i++){
			for(int j=1;j<=n/2;j++){
				if(c[i].id==a[j].id&&flag==0){
					a2-=a[j].m;
					num++;
					a2+=a[num].m;
					flag=1;
				}
				if(b[j].id==c[i].id&&fa==0){
					b2-=b[j].m;
					num2++;
					b2+=b[num2].m;
					fa=1;
				}
				if(flag==1&&fa==1) break;
			}
		}
		maxn=0;
		maxn=max(a2,b2);
		ans+=maxn;
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) test();
    return 0;
}

