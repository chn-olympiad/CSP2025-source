#include<bits/stdc++.h>
using namespace std;
int n,sum,book[100001],cnt1,cnt2,cnt3;
struct node{
	int v,id;
}a[100001],b[100001],c[100001],c1[50001],c2[50001],c3[50001];
bool cmp(node a,node b){
	return a.v>b.v;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].v>>b[i].v>>c[i].v;
		a[i].id=b[i].id=c[i].id=i;
	}
	if(n==2){
		if(2*a[1].v>b[1].v+c[1].v){
			cout<<a[1].v+max(b[2].v,c[2].v);
			return 0;
		}
		if(2*b[1].v>a[1].v+c[1].v){
			cout<<b[1].v+max(a[2].v,c[2].v);
			return 0;
		}
		if(2*c[1].v>b[1].v+a[1].v){
			cout<<c[1].v+max(b[2].v,a[2].v);
			return 0;
		}
	}//5pts
	if(b[1].v==c[1].v==b[2].v==c[2].v){
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n/2;i++){
			sum+=a[i].v;
		}
		cout<<sum;
		return 0;
	}//5pts
	//(¤Ã¨i¨s©n¨t¨ic)²»»á
	//sort(a+1,a+1+n,cmp);
	//sort(b+1,b+1+n,cmp);
	//sort(c+1,c+1+n,cmp);
	if(c[1].v==c[2].v==c[3].v==0){
		for(int i=1;i<=n;i++){
			if(a[i].v>b[i].v){
				cnt1++;
				c1[cnt1].id=a[i].id;
				c1[cnt1].v=a[i].v;
				if(cnt1>n/2){
					sort(c1+1,c1+1+cnt1,cmp);
					sum-=c1[cnt1].v;
					c1[cnt1].v=0;
					book[c1[cnt1].id]=0;
					book[i]=1;
					c1[cnt1].id=0;
				}
				sum+=c1[i].v;
			}
			else{
				cnt2++;
				c2[cnt2].id=b[i].id;
				c2[cnt2].v=b[i].v;
				if(cnt2>n/2){
					sort(c2+1,c2+1+cnt2,cmp);
					sum-=c2[cnt2].v;
					c2[cnt2].v=0;
					book[c2[cnt2].id]=0;
					book[i]=1;
					c2[cnt2].id=0;
				}
				sum+=c2[i].v;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i].v*2>b[i].v+c[i].v){
			cnt1++;
			c1[cnt1].id=a[i].id;
			c1[cnt1].v=a[i].v;
			if(cnt1>n/2){
				sort(c1+1,c1+1+cnt1,cmp);
				sum-=c1[cnt1].v;
				c1[cnt1].v=0;
				book[c1[cnt1].id]=0;
				book[i]=1;
				c1[cnt1].id=0;
			}
			sum+=c1[i].v;
		}
		if(b[i].v*2>a[i].v+c[i].v){
			cnt2++;
			c2[cnt2].id=b[i].id;
			c2[cnt2].v=b[i].v;
			if(cnt2>n/2){
				sort(c2+1,c2+1+cnt2,cmp);
				sum-=c2[cnt2].v;
				c2[cnt2].v=0;
				book[c2[cnt2].id]=0;
				book[i]=1;
				c2[cnt2].id=0;
			}
			sum+=c2[i].v;
		}
		if(c[i].v*2>b[i].v+a[i].v){
			cnt3++;
			c3[cnt3].id=c[i].id;
			c3[cnt3].v=c[i].v;
			if(cnt3>n/2){
				sort(c3+1,c3+1+cnt3,cmp);
				sum-=c3[cnt3].v;
				c3[cnt3].v=0;
				book[c3[cnt3].id]=0;
				book[i]=1;
				c3[cnt3].id=0;
			}
			sum+=c3[i].v;
		}
	}
	cout<<sum;
}
