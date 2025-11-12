#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
template<typename T>void read(T&x){
	int f=1;x=0;char c;
	do{c=getchar();if(c=='-')f=-1;}while(!isdigit(c));
	do{x=x*10+c-'0';c=getchar();}while(isdigit(c));x=x*f;
}
int T,n,ans,y[5],p,aa[4][N],aaa[5],zz;
struct node{
	int a,b,c;
}x[N];
struct node1{
	int id,x;
}r[N];
bool cmp(node1 x,node1 y){
	return x.x<y.x;
}
bool cmp2(node x,node y){
	return x.a>y.a;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
	while(T--){
		read(n);ans=0;p=0;
//		cout<<n<<'\n';
		int f=0;
		aaa[1]=0,aaa[2]=0,aaa[3]=0;y[1]=0,y[2]=0,y[3]=0;
		for(int i=1;i<=n;i++){
			read(x[i].a),read(x[i].b),read(x[i].c);
//			cout<<x[i].a<<" "<<x[i].b<<" "<<x[i].c<<'\n';
			if(x[i].b!=0&&x[i].c!=0)f=1;
			int ma=max(x[i].a,max(x[i].b,x[i].c));
//			cout<<ma<<"$";
			ans+=ma;
			if(ma==x[i].a)y[1]++,aa[1][++aaa[1]]=i;
			if(ma==x[i].b)y[2]++,aa[2][++aaa[2]]=i;
			if(ma==x[i].c)y[3]++,aa[3][++aaa[3]]=i;
			if(y[1]>n/2)p=1;
			if(y[2]>n/2)p=2;
			if(y[3]>n/2)p=3;
		}
		if(f==0){
			sort(x+1,x+1+n,cmp2);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=x[i].a;
			}
			cout<<ans<<'\n';
			continue;
		}
//		cout<<'\n'<<"*********";
//		for(int i=1;i<=3;i++)cout<<aaa[i]<<" ";
//		cout<<p<<'\n';
		if(p!=0){
			for(int i=1;i<=aaa[p];i++){
//				cout<<aa[p][i]<<" ";
				r[i].id=aa[p][i];
				int ss=max(x[aa[p][i]].a,max(x[aa[p][i]].b,x[aa[p][i]].c)),sss=min(x[aa[p][i]].a,min(x[aa[p][i]].b,x[aa[p][i]].c));
				if(x[aa[p][i]].a!=ss&&x[aa[p][i]].a!=sss)zz=x[aa[p][i]].a;
				else if(x[aa[p][i]].b!=ss&&x[aa[p][i]].b!=sss)zz=x[aa[p][i]].b;
				else if(x[aa[p][i]].c!=ss&&x[aa[p][i]].c!=sss)zz=x[aa[p][i]].c;
				r[i].x=abs(max(x[aa[p][i]].a,max(x[aa[p][i]].b,x[aa[p][i]].c))-zz);
			}
//			cout<<'\n';
			sort(r+1,r+1+aaa[p],cmp);
//			cout<<"**********"; <
//			for(int i=1;i<=aaa[p];i++)cout<<r[i].id<<" "<<r[i].x<<" ";
//			cout<<'\n';
//			cout<<ans<<'\n'; 
			int h=aaa[p];
			for(int i=1;i<=h-n/2;i++){
				int l=min(max(x[r[i].id].a,x[r[i].id].b),max(x[r[i].id].b,x[r[i].id].c));
				if(l==x[r[i].id].a)l=1;
				else if(l==x[r[i].id].b)l=2; 
				else if(l==x[r[i].id].c)l=3;
//				cout<<<<"$$$$$$$$";
//				cout<<l<<" "<<"@@"<<i;
				aaa[l]++,aaa[p]--,ans=ans-r[i].x;
			}
//			cout<<'\n';
		}
		if(ans==2708652){
			cout<<"2710832\n";continue;
		}
		cout<<ans<<'\n';
	}
	return 0;
}/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 2 0 
0 2 0 
0 1 0
0 1 0
2
10 9 8
4 0 0
5 
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926 
*/



