#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,a[100005][4],co[100005][4],num,aa,bb,cc,ans;
void cmp(ll a,ll b,ll c,int p){
	if (a>=b&&a>=c){
		ans+=a;
		co[p][1]=1;
		aa++;
		if (b>=c) co[p][2]=2,co[p][3]=3;
		else co[p][2]=3,co[p][3]=2;
	}
	else if (b>=a&&b>=c){
		ans+=b;
		co[p][1]=2;
		bb++;
		if (a>=c) co[p][2]=1,co[p][3]=3;
		else co[p][2]=3,co[p][3]=1;
	}
	else if (c>=a&&c>=b){
		ans+=c;
		co[p][1]=3;
		cc++;
		if (a>=b) co[p][2]=1,co[p][3]=2;
		else co[p][2]=2,co[p][3]=1;
	}
	return;
}
struct node{
	ll num,x;
}w[100005];
bool comp(node d,node e){
	return d.num<e.num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;i++){
		aa=0,bb=0,cc=0,ans=0;
		cin>>n;
		num=n/2;
		for (int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			cmp(a[j][1],a[j][2],a[j][3],j);
		}
		if(aa<=num&&bb<=num&&cc<=num){
			cout<<ans<<endl;
			continue;
		}
		int cou=1;
		if (aa>num){
			int f=aa-num;
			for (int j=1;j<=n;j++){
				if (co[j][1]!=1) continue;
				w[cou].num=a[j][1],w[cou].x=j;
				cou++;
			}
			sort(w+1,w+cou,comp);
			for (int j=1;j<=f;j++){
				if (co[j][2]==2){
					bb++;
					ans=ans-w[j].num+a[w[j].x][2];
				}
				else {
					cc++;
					ans=ans-w[j].num+a[w[j].x][3];
				}
			}
		}
		else if (bb>num){
			int f=bb-num;
			for (int j=1;j<=n;j++){
				if (co[j][1]!=2) continue;
				w[cou].num=a[j][2],w[cou].x=j;
				cou++;
			}
			sort(w+1,w+cou,comp);
			for (int j=1;j<=f;j++){
				if (co[j][2]==1){
					aa++;
					ans=ans-w[j].num+a[w[j].x][1];
				}
				else {
					cc++;
					ans=ans-w[j].num+a[w[j].x][3];
				}
			}
		}
		else if (cc>num){
			int f=cc-num;
			for (int j=1;j<=n;j++){
				if (co[j][1]!=3) continue;
				w[cou].num=a[j][3],w[cou].x=j;
				cou++;
			}
			sort(w+1,w+cou,comp);
			for (int j=1;j<=f;j++){
				if (co[j][2]==1){
					aa++;
					ans=ans-w[j].num+a[w[j].x][1];
				}
				else {
					bb++;
					ans=ans-w[j].num+a[w[j].x][2];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}






