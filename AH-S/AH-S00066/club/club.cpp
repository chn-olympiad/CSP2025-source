#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct S{
	int id1,id2,id3,m;
	bool f;
}q[N];
int dp[N];
int cmp(const S &x,const S &y){
	return x.id1>y.id1;
}
int cmp1(const S &x,const S &y){
	return x.id1>y.id1;
	if(x.id1==x.id2) return x.id2<y.id2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int f4=0;
		int n;
		cin>>n;
		int f1=1,f2=1;
		for(int i=1;i<=n;i++){
			cin>>q[i].id1>>q[i].id2>>q[i].id3;
			if(q[i].id2!=0 || q[i].id3!=0) f1=0;
			if(q[i].id3!=0) f2=0; 
		}
		if(n==2){
			f4=1;
			int a,b,c,d,e,f;
			a=q[1].id1,b=q[1].id2,c=q[1].id3;
			d=q[2].id1,e=q[2].id2,f=q[2].id3;
			long long cnt=max(max(max(a+e,a+f),max(b+d,b+f)),max(c+d,c+e));
			cout<<cnt<<endl;
		}
 		else if(f1==1){
			sort(q+1,q+n+1,cmp);
			long long cnt=0;
			for(int i=1;i<=n/2;i++) cnt+=q[i].id1;
			cout<<cnt<<endl;
		}
		else if(f2==1 && f1==0){
			int a,b;
			a=b=n/2;
			long long cnt=0;
			sort(q+1,q+n+1,cmp1);
			dp[0]=0;
			for(int i=1;i<=n;i++){
				int maxx=max(q[i].id1,q[i].id2);
				if(maxx==q[i].id1) a--;
				else b--;
				
				if(a<0) maxx=q[i].id2;
				if(b<0) maxx=q[i].id1;
				cnt+=maxx;
			}
			cout<<cnt<<endl;
		}
		else{
			for(int i=1;i<=n;i++){
			int maxx;
				maxx=max(q[i].id1,q[i].id2);
				maxx=max(maxx,q[i].id3);
				dp[i]=dp[i-1]+maxx;
			}
			cout<<dp[n]<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

