#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
int n,t;
struct node{
	int a1,a2,a3;
}a[MAXN];
int stn(node b){
	int bn=b.a1+b.a2+b.a3;
	bn-=max(b.a1,max(b.a2,b.a3));
	bn-=min(b.a1,min(b.a2,b.a3));
	bn=max(b.a1,max(b.a2,b.a3))-bn;
	return bn;
}
struct stv{
	int il,num;
}st[MAXN];
bool cmp(stv b,stv c){
	return b.num<c.num;
}
bool cmp2(node b,node c){
	return max(b.a1,b.a2)>max(c.a1,c.a2);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		long long ans=0;
		int ma=n/2;
		int l1=0,l2=0,l3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			st[i].num=stn(a[i]);
			st[i].il=i;
		}
		for(int i=1;i<=n;i++){
			ans+=max(a[i].a1,max(a[i].a2,a[i].a3));
			if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3) l1++;
			else if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3) l2++;
			else l3++;
		}
//		cout<<l1<<" "<<l2<<" "<<l3<<" "<<"\n";
		sort(st+1,st+n+1,cmp);
//		for(int i=1;i<=n;i++)cout<<st[i].num<<" "<<st[i].il<<"\n";
		int k=1;
		int i=st[1].il;
		if(a[1].a2==a[1].a3&&a[1].a3==0&&n==1e5){
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=ma;i++){
				ans+=a[i].a1;
			}
			cout<<ans<<"\n";
		}
		if(l1>ma){
			while(l1>ma){
				if(a[i].a1==max(a[i].a1,max(a[i].a2,a[i].a3))){
					l1--;ans-=a[i].a1;
					if(a[i].a2>a[i].a3){
						ans+=a[i].a2;l2++;
						if(l2>ma){
							int m=1e9;
							for(int j=1;j<=n;j++)if(a[j].a2>a[j].a3)
								m=min(m,a[j].a2-a[j].a3);
							ans-=m;l2--;l3++;
						}
					}else{
						ans+=a[i].a3;l3++;
						if(l3>ma){
							int m=1e9;
							for(int j=1;j<=n;j++)if(a[j].a3>a[j].a2)
								m=min(m,a[j].a3-a[j].a2);
							ans-=m;l3--;l2++;
						}
					}
					
				}
				k++;
				i=st[k].il;
			}
		}else if(l2>ma){
			while(l2>ma){
				if(a[i].a2==max(a[i].a1,max(a[i].a2,a[i].a3))){
					l2--;ans-=a[i].a2;
					if(a[i].a1>a[i].a3){
						ans+=a[i].a1;l1++;
						if(l1>ma){
							int m=1e9;
							for(int j=1;j<=n;j++)if(a[j].a1>a[j].a3)
								m=min(m,a[j].a1-a[j].a3);
							ans-=m;l1--;l3++;
						}
					}else{
						ans+=a[i].a3;l3++;
						if(l3>ma){
							int m=1e9;
							for(int j=1;j<=n;j++)if(a[j].a3>a[j].a1)
								m=min(m,a[j].a3-a[j].a1);
							ans-=m;l3--;l1++;
						}
					}
					
				}
				k++;
				i=st[k].il;
			}
		}else if(l3>ma){
			while(l3>ma){
				if(a[i].a1==max(a[i].a1,max(a[i].a2,a[i].a3))){
					l3--;ans-=a[i].a3;
					if(a[i].a2>a[i].a1){
						ans+=a[i].a2;l2++;
						if(l2>ma){
							int m=1e9;
							for(int j=1;j<=n;j++)if(a[j].a2>a[j].a1)
								m=min(m,a[j].a2-a[j].a1);
							ans-=m;l2--;l1++;
						}
					}else{
						ans+=a[i].a1;l1++;
						if(l1>ma){
							int m=1e9;
							for(int j=1;j<=n;j++)if(a[j].a1>a[j].a2)
								m=min(m,a[j].a1-a[j].a2);
							ans-=m;l1--;l2++;
						}
					}
					
				}
				k++;
				i=st[k].il;
			}
		}else{
			cout<<ans<<"\n";
			continue;
		}
		cout<<ans<<"\n";
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
