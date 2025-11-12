#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int a,b,c;
	int gx;
}stu[200005];
int sa,sb,sc;
int a1,a2,a3;
bool cmp(node x,node y){
	return x.gx>y.gx;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sa=sb=sc=a1=a2=a3=0;
		for(int i=1;i<=n;i++){
			stu[i].a=0;
			stu[i].b=0;
			stu[i].c=0;
			stu[i].gx=-20001;
		}
		for(int i=1;i<=n;i++){
			cin>>stu[i].a>>stu[i].b>>stu[i].c;
			sa+=stu[i].a;
			sb+=stu[i].b;
			sc+=stu[i].c;
		}
		//a
		for(int i=1;i<=n;i++)stu[i].gx=max(stu[i].b,stu[i].c)-stu[i].a;
		sort(stu+1,stu+1+n,cmp);
		a1=sa;
		for(int i=1;i<=n;i++){
			if(stu[i].gx>0||i<=n/2)a1+=stu[i].gx;
		}
//		cout<<a1<<'\n';
//		for(int i=1;i<=n;i++)cout<<stu[i].gx<<" ";
//		cout<<'\n';
		//b
		for(int i=1;i<=n;i++)stu[i].gx=max(stu[i].a,stu[i].c)-stu[i].b;
		sort(stu+1,stu+1+n,cmp);
		a2=sb;
		for(int i=1;i<=n;i++){
			if(stu[i].gx>0||i<=n/2)a2+=stu[i].gx;
		}
//		cout<<a2<<'\n';
//		for(int i=1;i<=n;i++)cout<<stu[i].gx<<" ";
//		cout<<'\n';
		//c
		for(int i=1;i<=n;i++)stu[i].gx=max(stu[i].b,stu[i].a)-stu[i].c;
		sort(stu+1,stu+1+n,cmp);
		a3=sc;
		for(int i=1;i<=n;i++){
			if(stu[i].gx>0||i<=n/2)a3+=stu[i].gx;
		}
//		cout<<a3<<'\n';
//		for(int i=1;i<=n;i++)cout<<stu[i].gx<<" ";
//		cout<<'\n';
		cout<<min(a1,min(a2,a3))<<'\n';
	}
	return 0;
}
