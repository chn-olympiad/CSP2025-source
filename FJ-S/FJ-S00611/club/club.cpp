#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
ll read(){
	ll w=1,x=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return w*x;
}
void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar((x%10)+'0');
}
ll ans,dp[205][205],d1[N],d2[N],d3[N];
int n,cnt,sum[10];
bool vis[N],flag2,flag3;
struct node{
	int id,d,val;
	bool operator <(const node& rhs)const{
		if(val==rhs.val) return d<rhs.d;
		return val>rhs.val;
	}
}a[N*3];
inline void input(int id,int d){
	a[++cnt].id=id;
	a[cnt].d=d;
	a[cnt].val=read();
	if(d==1){
		d1[id]=a[cnt].val;
	}
	if(d==2){
		d2[id]=a[cnt].val;
	}
	if(d==3){
		d3[id]=a[cnt].val;
	}
	if(d==2&&a[cnt].val!=0) flag2=false;
	if(d==3&&a[cnt].val!=0) flag3=false;
}
void work(){
	n=read(),cnt=ans=sum[1]=sum[2]=sum[3]=0;
	flag2=flag3=true;
	for(int i=1;i<=n;i++){
		vis[i]=false;
		input(i,1),input(i,2),input(i,3);
	}
	if(n<=200){
		memset(dp,0,sizeof(dp));
		for(register int i=1;i<=n;i++){
			for(register int A=n;A>=0;A--){
				for(register int B=n;B>=0;B--){
					if((i-A-B)<0) continue;
//					if(A==0&&B==0) dp[A][B]+=a[(i-1)*3+3].val;
					if(A==0&&B==0) dp[A][B]+=d3[i];
					else if(A==0){
//						dp[A][B]=max(dp[A][B]+a[(i-1)*3+3].val,dp[A][B-1]+a[(i-1)*3+2].val);
						dp[A][B]=max(dp[A][B]+d3[i],dp[A][B-1]+d2[i]);
					}else if(B==0){
//						dp[A][B]=max(dp[A][B]+a[(i-1)*3+3].val,dp[A-1][B]+a[(i-1)*3+1].val);
						dp[A][B]=max(dp[A][B]+d3[i],dp[A-1][B]+d1[i]);
					}else{
						dp[A][B]=max(dp[A][B]+d3[i],max(dp[A][B-1]+d2[i],dp[A-1][B]+d1[i]));
//						dp[A][B]=max(dp[A][B]+a[(i-1)*3+3].val,max(dp[A][B-1]+a[(i-1)*3+2].val,dp[A-1][B]+a[(i-1)*3+1].val));
					}
//					if(A!=0) dp[A][B]=max(dp[A][B]+a[(i-1)*3+3].val,dp[A-1][B]+a[(i-1)*3+1].val);
//					if(B!=0) dp[A][B]=max(dp[A][B]+a[(i-1)*3+3].val,dp[A][B-1]+a[(i-1)*3+2].val);
				}
			}
		}
		for(register int A=0;A<=(n/2);A++){
			for(register int B=0;B<=(n/2);B++){
				if((n-A-B)>(n/2)) continue;
//				cout<<"("<<A<<" "<<B<<" "<<dp[A][B]<<") ";
				ans=max(ans,dp[A][B]);
			}
//			cout<<endl;
		}
	}
//	else if(flag2&&(!flag3)){//13,14
//		something//give up
//	}
	else{
		//	cout<<endl;
		sort(a+1,a+1+cnt);
	//	for(int i=1;i<=cnt;i++){
	//		cout<<a[i].id<<" "<<a[i].d<<" "<<a[i].val<<endl;
	//	}
		for(int i=1;i<=cnt;i++){
			int id=a[i].id,d=a[i].d,val=a[i].val;
			if(vis[id]||sum[d]>=(n/2)) continue;
	//		cout<<id<<" "<<d<<" "<<val<<endl;
			vis[id]=true;
			ans+=val;
			sum[d]++;
		}
	}
	write(ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while(t--){
		work();
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//CaoNiMaB