#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
struct node{
	long long A,B,C;
}a[N],b[N];
inline bool cmp(node x,node y){
	return max(x.A,max(x.B,x.C))>max(y.A,max(y.B,y.C));
}
struct node2{
	long long val,id;
}tmp[N];
inline bool cmpA(node2 x,node2 y){
	long long k1=a[x.id].A-x.val;
	long long k2=a[y.id].A-y.val;
	return k1>k2;
}
inline bool cmpB(node2 x,node2 y){
	long long k1=a[x.id].B-x.val;
	long long k2=a[y.id].B-y.val;
	return k1>k2;
}
inline bool cmpC(node2 x,node2 y){
	long long k1=a[x.id].C-x.val;
	long long k2=a[y.id].C-y.val;
	return k1>k2;
}
long long n,t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(long long i=1;i<=n;i++) cin>>a[i].A>>a[i].B>>a[i].C;
		for(long long i=1;i<=n;i++) b[i]=a[i];
		sort(a+1,a+n+1,cmp);
		long long cntA=0,cntB=0,cntC=0,ans=0;
		for(long long i=1;i<=n;i++){
			if(cntA<(n/2)&&cntB<(n/2)&&cntC<(n/2)){
				if(a[i].A>=a[i].B&&a[i].A>=a[i].C) cntA++,ans+=a[i].A;
				else if(a[i].B>=a[i].A&&a[i].B>=a[i].C) cntB++,ans+=a[i].B;
				else if(a[i].C>=a[i].B&&a[i].C>=a[i].A) cntC++,ans+=a[i].C;
			}
			else{
				ans=0;
				break;
			}
		}
		long long ansA=0,ansB=0,ansC=0;
		//A
		for(long long i=1;i<=n;i++) a[i]=b[i];
		for(long long i=1;i<=n;i++)	tmp[i].val=max(a[i].B,a[i].C),tmp[i].id=i;
		sort(tmp+1,tmp+n+1,cmpA);
		for(long long i=1;i<=n/2;i++){
			ansA+=a[tmp[i].id].A;
		}
		for(long long i=n/2+1;i<=n;i++) ansA+=tmp[i].val;
		//B
		for(long long i=1;i<=n;i++) a[i]=b[i];
		for(long long i=1;i<=n;i++)	tmp[i].val=max(a[i].A,a[i].C),tmp[i].id=i;
		sort(tmp+1,tmp+n+1,cmpB);
		for(long long i=1;i<=n/2;i++){
			ansB+=a[tmp[i].id].B;
		}
		for(long long i=n/2+1;i<=n;i++) ansB+=tmp[i].val;
		//C
		for(long long i=1;i<=n;i++) a[i]=b[i];
		for(long long i=1;i<=n;i++)	tmp[i].val=max(a[i].B,a[i].A),tmp[i].id=i;
		sort(tmp+1,tmp+n+1,cmpC);
		for(long long i=1;i<=n/2;i++){
			ansC+=a[tmp[i].id].C;
		}
		for(long long i=n/2+1;i<=n;i++) ansC+=tmp[i].val;
		//
		ans=max(ans,max(ansA,max(ansB,ansC)));
		cout<<ans<<endl;
		for(long long i=1;i<=n;i++) a[i].A=0,a[i].B=0,a[i].C=0,b[i]=a[i],tmp[i].id=0,tmp[i].val=0;
		n=0;
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
