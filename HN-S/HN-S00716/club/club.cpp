#include<bits/stdc++.h>
using namespace std;
struct node{
	int d1,d2,d3,c1_2,w1,w2,cha;
}a[100005];
int n;
bool cmp1(node x,node y){
	return x.d1>y.d1;
}
bool cmp_c_1_2(node x,node y){
	return x.c1_2>y.c1_2;
}
bool cmp_cha(node x,node y){
	return x.cha>y.cha;
}
void work(){
	bool dq1=0,dq2=0,dq3=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].d1>>a[i].d2>>a[i].d3;
		if(a[i].d2!=0){
			dq2=1;
		}
		if(a[i].d3!=0){
			dq3=1;
		}
		a[i].c1_2=a[i].d1-a[i].d2;
		int fi=max(a[i].d1,max(a[i].d2,a[i].d3));
		if(fi==a[i].d1){
			int se=max(a[i].d2,a[i].d3);
			if(se==a[i].d2){
				a[i].w2=2;
				a[i].cha=a[i].d1-a[i].d2;
			}else{
				a[i].w2=3;
				a[i].cha=a[i].d1-a[i].d3;
			}
			a[i].w1=1;
		}
		if(fi==a[i].d2){
			int se=max(a[i].d1,a[i].d3);
			if(se==a[i].d1){
				a[i].w2=1;
				a[i].cha=a[i].d2-a[i].d1;
			}else{
				a[i].w2=3;
				a[i].cha=a[i].d2-a[i].d3;
			}
			a[i].w1=2;
		}
		if(fi==a[i].d3){
			int se=max(a[i].d2,a[i].d1);
			if(se==a[i].d1){
				a[i].w2=1;
				a[i].cha=a[i].d3-a[i].d1;
			}else{
				a[i].w2=2;
				a[i].cha=a[i].d3-a[i].d2;
			}
			a[i].w1=3;
		}
	}
	if(dq2==dq1&&dq2==dq3){
		sort(a+1,a+1+n,cmp1);
		int ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=a[i].d1;
		}
		cout<<ans;
		return ;
	}
	if(dq3==dq1){
		sort(a+1,a+1+n,cmp_c_1_2);
		int ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=a[i].d1;
		}
		for(int i=n/2+1;i<=n;i++){
			ans+=a[i].d2;
		}
		cout<<ans;
		return ;
	}
	sort(a+1,a+1+n,cmp_cha);
	int tot1,tot2,tot3;
	tot1=tot2=tot3=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		int e1=a[i].w1,e2=a[i].w2;
		if(e1==1){
			if(tot1<n/2){
				tot1++;
				ans+=a[i].d1;
			}else{
				if(e2==2){
					tot2++;
					ans+=a[i].d2;
				}else{
					ans+=a[i].d3;
					tot3++;
				}
			}
		}else if(e1==2){
			if(tot2<n/2){
				tot2++;
				ans+=a[i].d2;
			}else{
				if(e2==1){
					tot1++;
					ans+=a[i].d1;
				}else{
					ans+=a[i].d3;
					tot3++;
				}
			}
		}else{
			if(tot3<n/2){
				ans+=a[i].d3;
				tot3++;
			}else{
				if(e2==2){
					tot2++;
					ans+=a[i].d2;
				}else{
					tot1++;
					ans+=a[i].d1;
				}
			}
		}
	}
	cout<<ans;
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		work();
		cout<<"/n";
	}
}
