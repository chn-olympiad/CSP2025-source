#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
struct node{
	int le1,le2,le3,mx,ides;
}st[N];
int cmp(node a,node b){
	return a.le1>b.le1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=200){
			int ans1=0,ans2=0;
			int an1,an2,an3;
			for(int i=1;i<=n;i++){
				cin>>st[i].le1>>st[i].le2>>st[i].le3;
				st[i].mx=max(st[i].le1,max(st[i].le2,st[i].le3));
				if(st[i].mx==st[i].le1) st[i].ides=1;
				else if(st[i].mx==st[i].le2) st[i].ides=2;
				else st[i].ides=3;
			}
			an1=an2=an3=0;
			for(int i=1;i<=n;i++){
				if(st[i].ides==1){
					if(st[i].le1==st[i].mx&&an1<n/2) ans1+=st[i].le1,an1++;
					else if(st[i].le2>=st[i].le3&&an2<n/2) ans1+=st[i].le2,an2++;
					else ans1+=st[i].le3,an3++;
				}else if(st[i].ides==2){
					if(st[i].le2==st[i].mx&&an2<n/2) ans1+=st[i].le2,an2++;
					else if(st[i].le1>=st[i].le3&&an1<n/2) ans1+=st[i].le1,an1++;
					else ans1+=st[i].le3,an3++;
				}else{
					if(st[i].le3==st[i].mx&&an3<n/2) ans1+=st[i].le3,an3++;
					else if(st[i].le1>=st[i].le2&&an1<n/2) ans1+=st[i].le1,an1++;
					else ans1+=st[i].le2,an2++;
				}
			}
			an1=an2=an3=0;
			for(int i=n;i>=1;i--){
				if(st[i].ides==1){
					if(st[i].le1==st[i].mx&&an1<n/2) ans2+=st[i].le1,an1++;
					else if(st[i].le2>=st[i].le3&&an2<n/2) ans2+=st[i].le2,an2++;
					else ans2+=st[i].le3,an3++;
				}else if(st[i].ides==2){
					if(st[i].le2==st[i].mx&&an2<n/2) ans2+=st[i].le2,an2++;
					else if(st[i].le1>=st[i].le3&&an1<n/2) ans2+=st[i].le1,an1++;
					else ans2+=st[i].le3,an3++;
				}else{
					if(st[i].le3==st[i].mx&&an3<n/2) ans2+=st[i].le3,an3++;
					else if(st[i].le1>=st[i].le2&&an1<n/2) ans2+=st[i].le1,an1++;
					else ans2+=st[i].le2,an2++;
				}
			}
			cout<<max(ans1,ans2)<<endl;
		}else{
			bool fool1=1,fool2=1,fool3=1;
			for(int i=1;i<=n;i++){
				cin>>st[i].le1>>st[i].le2>>st[i].le3;
				if(st[i].le1!=0) fool1=0;
				if(st[i].le2!=0) fool2=0;
				if(st[i].le3!=0) fool3=0;
			}
			if(fool1==0&&fool2==1&&fool3==1){
				sort(st+1,st+1+n,cmp);
				int ans=0;
				for(int i=1;i<=n/2;i++)
					ans+=st[i].le1;
				cout<<ans;
			}else{
				int ans1=0,ans2=0;
				int an1,an2;
				an1=an2=0;
				for(int i=1;i<=n;i++){
					if(st[i].le1>st[i].le2&&an1<n/2) ans1+=st[i].le1,an1++;
					else ans1+=st[i].le2,an2++;
				}
				an1=an2=0;
				for(int i=n;i<=1;i--){
					if(st[i].le1>st[i].le2&&an1<n/2) ans2+=st[i].le1,an1++;
					else ans2+=st[i].le2,an2++;
				}
				cout<<max(ans1,ans2);
			}
		}
	}
	return 0;
}