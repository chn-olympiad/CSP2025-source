#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int t,n,m,ans;
int s1,s2,s3;
int vis1,vis2,vis3;
struct node{
	int a1,a2,a3;
	int d1,d2;
}p[N];
bool cmp1(node x,node y){
	return x.a1>y.a1;
}
bool cmp2(node x,node y){
	return x.a2>y.a2;
}
bool cmp3(node x,node y){
	return x.a3>y.a3;
}
void solve(){
	sort(p+1,p+1+n,cmp1);
	for(int i=1;i<=m;i++)ans+=p[i].a1;
	cout<<ans<<endl;
	return ;
}
void solve1(){
	int sum=0;
	sort(p+1,p+1+n,cmp1);
	for(int i=1;i<=n;i++){
		if(p[i].d1==1){
			ans+=p[i].a1;
			p[i].a1==-1;
			sum++;
		}
		if(sum==m)break;
	}
	if(sum!=m){
		for(int i=1;i<=n;i++){
			if(p[i].a1==-1&&p[i].d1!=2){
				ans+=p[i].a2;
				sum++;
			}
			if(sum==m)break;
		}
	}
	sum=0;
	sort(p+1,p+1+n,cmp2);
	for(int i=1;i<=n;i++){
		if(p[i].d1==2){
			ans+=p[i].a2;
			p[i].a2==-1;
			sum++;
		}
		if(sum==m)break;
	}
	if(sum!=m){
		for(int i=1;i<=n;i++){
			if(p[i].a2==-1&&p[i].d1!=2){
				ans+=p[i].a1;
				sum++;
			}
			if(sum==m)break;
		}
	}
	cout<<ans;
	return ;
	
}
void solve4(){
	int b=max(p[1].a1,p[1].a2),c=max(p[2].a1,p[2].a2);
	b=max(b,p[1].a3),c=max(c,p[2].a3);
	cout<<b+c<<endl;
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t>>n;
	m=n/2;
	while(t--){
		for(int i=1;i<=n;i++){
			cin>>p[i].a1;
			cin>>p[i].a2;
			cin>>p[i].a3;
			if(p[i].a2!=0 || p[i].a3!=0)s1=1;
			if(p[i].a3!=0)s2=1;
			if(p[i].a1>p[i].a2&&p[i].a1>p[i].a3)p[i].d1=1,vis1++;
			else if(p[i].a1>p[i].a2&&p[i].a1>p[i].a3)p[i].d1=2,vis2++;
			else p[i].d1=3,vis3++;
		}
		if(s1==0)solve();
		else if(n==2)solve4();
		else solve1();
		
		
		
		
		
		
		
		
		
		
		
		
		
		for(int i=1;i<=n;i++){
			p[i].a1=0;p[i].a2=0;p[i].a3=0;
		}
		s1=0;
		
	}
	
	
	
	
	
	
	
	
	
	
	return 0;
}

