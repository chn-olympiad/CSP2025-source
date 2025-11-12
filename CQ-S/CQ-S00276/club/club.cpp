#include<bits/stdc++.h>
using namespace std;
struct node{
	int s,id;
}a1[100005],a2[100005],a3[100005];
bool cmp(node a,node b)
{
	return a.s>b.s;
}
int main()
{
	int t;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,z1=0,z2=0,z3=0,z1r=0,z2r=0,z3r=0,ans=0,h1[100005],h2[100005],h3[100005],mx;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>h1[i]>>h2[i]>>h3[i];
			mx=max(h1[i],max(h2[i],h3[i]));
			if(mx==h1[i])
			z1r++,z1+=h1[i],a1[z1r].s=h1[i],a1[z1r].id=i;
			else if(mx==h2[i]) 
			z2r++,z2+=h2[i],a2[z2r].s=h2[i],a2[z2r].id=i;
			else 
			z3r++,z3+=h3[i],a3[z3r].s=h3[i],a3[z3r].id=i;
			sort(a1+1,a1+1+n,cmp);
			sort(a2+1,a2+1+n,cmp);
			sort(a3+1,a3+1+n,cmp);
			ans+=mx;
		//	cout<<ans<<'\n';
			if(z1r>n/2){
					ans-=a1[z1r].s;
					ans+=max(h2[a1[i].id],h3[a1[i].id]);
					if(a2[z2r-1].s+a1[z1r].s>ans||a3[z3r-1].s+a1[z1r].s>ans) ans=max(a2[a1[i].id].s+a1[z1r].s,a3[a1[i].id].s+a1[z1r].s);
				//	cout<<max(a2[a1[i].id].s,a3[a1[i].id].s)<<' '<<1<<'\n';
					z1r--;
			}
			else if(z2r>n/2){
					ans-=a2[z2r].s;
				//	cout<<ans<<' ';
					ans+=max(h1[a2[i].id],h3[a2[i].id]);
					if(a1[z1r-1].s+a2[z2r].s>ans||a3[z3r-1].s+a2[z2r].s>ans) ans=max(a1[a2[i].id].s+a2[z2r].s,a3[a2[i].id].s+a2[z2r].s);
					z2r--;
				//	cout<<max(a1[a2[i].id].s,a3[a2[i].id].s)<<' '<<2<<'\n';
			} 
			else if(z3r>n/2){
					ans-=a3[z3r].s;
					ans+=max(h1[a3[i].id],h2[a3[i].id]);
					if(a2[z2r-1].s+a3[z3r].s>ans||a1[z1r-1].s+a3[z3r].s>ans) ans=max(a2[a3[i].id].s+a3[z3r].s,a1[a3[i].id].s+a3[z3r].s);
					z3r--;
			} 
		}
		cout<<ans<<'\n';
	}
		
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
