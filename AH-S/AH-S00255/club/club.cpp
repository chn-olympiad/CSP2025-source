#include<bits/stdc++.h>
using namespace std;
int t,n,t1[5],tp6[100005],m;
long long tp1,tp2,tp3;
struct node{
	int a1,a2,a3,mx1,mx2,ind1,ind2;
}a[100005];
bool cmp(int x,int y){
	return a[x].mx1-a[x].mx2<a[y].mx1-a[y].mx2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		tp1=tp2=tp3=m=t1[1]=t1[2]=t1[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3){
				a[i].ind1=1;
				a[i].mx1=a[i].a1;
				t1[1]++;
				tp1+=a[i].mx1;
				if(a[i].a2>=a[i].a3){
					a[i].ind2=2;
					a[i].mx2=a[i].a2;
				}
				else{
					a[i].ind2=3;
					a[i].mx2=a[i].a3;
				}
			}
			else if(a[i].a2>=a[i].a3){
				a[i].ind1=2;
				a[i].mx1=a[i].a2;
				t1[2]++;
				tp2+=a[i].mx1;
				if(a[i].a1>=a[i].a3){
					a[i].ind2=1;
					a[i].mx2=a[i].a1;
				}
				else{
					a[i].ind2=3;
					a[i].mx2=a[i].a3;
				}
			}
			else{
				a[i].ind1=3;
				a[i].mx1=a[i].a3;
				t1[3]++;
				tp2+=a[i].mx1;
				if(a[i].a2>=a[i].a1){
					a[i].ind2=2;
					a[i].mx2=a[i].a2;
				}
				else{
					a[i].ind2=1;
					a[i].mx2=a[i].a1;
				}
			}
		}
		if(t1[1]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].ind1==1){
					tp6[++m]=i;
				}
			}
		}
		else if(t1[2]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].ind1==2){
					tp6[++m]=i;
				}
			}
		}
		else if(t1[3]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].ind1==3){
					tp6[++m]=i;
				}
			}
		}
		else{
			cout<<tp1+tp2+tp3<<"\n";
			continue;
		}
		long long ans=tp1+tp2+tp3;
		sort(tp6+1,tp6+m+1,cmp);
		int tp9=max(t1[1],max(t1[2],t1[3]));
		for(int i=1;i<=tp9-n/2;i++){
			ans=ans+a[tp6[i]].mx2-a[tp6[i]].mx1;
			t1[a[i].ind1]--;
			t1[a[i].ind2]++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
