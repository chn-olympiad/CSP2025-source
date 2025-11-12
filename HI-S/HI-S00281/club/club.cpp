#include<bits/stdc++.h> 
using namespace std;
long long T; 
long long n;
long long p[100086][9];
long long baif[100086];
long long ea[100086],eb[100086];
bool cmm(long long x,long long y){
	return x>y;
}
bool op1(long long x,long long y){
	return p[x][1]>p[y][1];
}
bool op2(long long x,long long y){
	return p[x][2]>p[y][2];
}
long long dpd(long long x,long long a,long long b,long long c,long long sum){
	if(a>n/2||b>n/2||c>n/2)return 0;
	if(x==n+1){
		return sum;
	}
	long long g1=dpd(x+1,a+1,b,c,sum+p[x][1]);
	long long g2=dpd(x+1,a,b+1,c,sum+p[x][2]);
	long long g3=dpd(x+1,a,b,c+1,sum+p[x][3]);
	return max(max(g1,g2),max(g2,g3));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int ty=1;ty<=T;ty++){
		scanf("%lld",&n);
		bool flag1=true;
		bool flag2=true;
		long long ans=0;
		for(long long i=1;i<=n;i++){
			scanf("%lld%lld%lld",&p[i][1],&p[i][2],&p[i][3]);
			if((p[i][2]!=0||p[i][3]!=p[i][2])&&flag1)flag1=false;
			if((p[i][3]!=0||p[i][3]==p[i][2])&&flag2)flag2=false;
			baif[i]=p[i][1];
		}
		if(flag1){
			sort(baif+1,baif+1+n,cmm);
			for(int i=1;i<=n/2;i++)ans+=baif[i];
			cout<<ans<<endl;
			continue;
		}
		else if(flag2){
			cout<<dpd(1,0,0,INT_MAX,0)<<endl;
			continue;
		}
		cout<<dpd(1,0,0,0,0)<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
