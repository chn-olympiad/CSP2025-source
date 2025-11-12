#include<bits/stdc++.h>

typedef int IT;
typedef long long LL;
typedef __int128 int128;
typedef double DB;

#define pb push_back
#define fst first
#define sec second
#define psh push
#define PII pair<IT,IT>
#define PLI pair<LL,IT>
#define lowbit(x) ((x)&(-x))

using namespace std;

//const int N=5e5+10;
const int N=1e3+10,V=255;// 1048576;
const int YYPQ=1;

//void qread(auto &sum){
//    sum=0;
//    auto f=sum+1;
//    char ch=getchar();
//    while(ch<'0' || ch>'9'){if(ch=='-') f=-1;ch=getchar();}
//    while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-48;ch=getchar();}
//    sum*=f;
//    return;
//}
//
//void qp(auto x){
//    if(x>9) qp(x/10);
//    putchar(x%10+48);
//    return;
//}
//void qpp(auto x){
//    if(x<0) x=-x,putchar('-');
//    qp(x);
//    return;
//}

int n,k;
int a[N];

int sum[N];

//int f[N][N];
int f[3][N];
int cur;
int ans;

//struct BITqwq{
//	int t[V+100];
//	void clear(){
//		for(int i=1;i<=V+YYPQ;i++) t[i]=0;
//		return;
//	}
//	
//	void update(int x,int del){
//		for(;x<=V;x+=lowbit(x)) t[x]+=del;
//		return;
//	}
//	int query(int x){
//		if(!x) return 0;
//		int res=0;
//		for(;x;x-=lowbit(x)) res+=t[x];
//		return res;
//	}
//}BIT;

//bool ss[V+100];
unordered_map<int,bool>ss;

int main(){
    freopen("xor.in","r",stdin);
//    freopen("xor5.in","r",stdin);
    freopen("xor.out","w",stdout);

	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum[i]=sum[i-1]^a[i];
	
	int tn=0;
	for(int i=1;i<=n;i++){
//		for(int j=0;j<i;j++){
//		BIT.clear();
//		for(int j=0;j<=V;j++) ss[j]=0;
		ss.clear();
		for(int j=i-1;~j;j--){
//			f[i+1][j]=max(f[i+1][j],f[i][j]);
			f[cur^1][j]=max(f[cur^1][j],f[cur][j]);
			
//			if(sum[i]^sum[j-1]==k) f[i+1][i]=max(f[i+1][i],f[i][j]+1);
//			if((sum[i]^sum[j-1])==k) f[i+1][i]=max(f[i+1][i],f[i][j]+1);
//			int s=sum[i]^sum[j-1];

//			for(int p=j;p<i;p++){
//				tn++;
//				int s=sum[i]^sum[p];
//				if(s==k) f[i+1][i]=max(f[i+1][i],f[i][j]+1);
//			}

//			bool bbb=0;
//			for(int p=j;p<i;p++){
//				if((sum[i]^sum[p])==k){
//					bbb=1;
//					break;
//				}
//			}
//			if(bbb) f[i+1][i]=max(f[i+1][i],f[i][j]+1);
			
//			ss[sum[i]]=1;
			ss[sum[j]]=1;
			if(ss[k^sum[i]]) f[cur^1][i]=max(f[cur^1][i],f[cur][j]+1);
			tn++;
			
//			cout<<"1111\n";
//			cout<<"now:: "<<i<<" "<<j<<"\n";
//			cout<<((k^sum[i])-1)<<" "<<(k^sum[i])<<"\n";
//			if((k^sum[i])>=0){
//				f[i+1][i]=max(f[i+1][i],BIT.query((k^sum[i])+YYPQ)-BIT.query((k^sum[i])-1+YYPQ)+1);
//				BIT.update(sum[i]+YYPQ,f[i+1][i]);
//				f[i+1][i]=max(f[i+1][i],ss[(k^sum[i])+YYPQ]+1);
//				ss[sum[i]+YYPQ]=max(ss[sum[i]+YYPQ],f[i+1][i]);
//			}

//			ss[sum[i]]=1;
//			if(ss[(k^sum[i])]) f[i+1][i]=max(f[i+1][i],f[i][j]+1);
			
//			cout<<"1111\n";
			
		}
		cur^=1;
	}
//	printf("%d\n",tn);
	
	for(int i=0;i<=n;i++) ans=max(ans,f[cur][i]);
//	for(int i=1;i<=n+1;i++){
//		for(int j=0;j<i;j++) ans=max(ans,f[i][j]);// ,cout<<f[i][j]<<" ";
////		cout<<"\n";
//	}
	printf("%d\n",ans);
    return 0;
}
// 61	22	D:\GD-J01476\xor\xor.cpp	[Warning] suggest parentheses around comparison in operand of '^' [-Wparentheses]
// 10:02 for(int i=0;i<=n;i++) ans=max(ans,f[i+1][i]);
// Process exited after 0.129 seconds with return value 3221225477

/*
from: dp(BIT).cpp
#include<bits/stdc++.h>

typedef int IT;
typedef long long LL;
typedef __int128 int128;
typedef double DB;

#define pb push_back
#define fst first
#define sec second
#define psh push
#define PII pair<IT,IT>
#define PLI pair<LL,IT>
#define lowbit(x) ((x)&(-x))

using namespace std;

//const int N=5e5+10;
const int N=1e3+10,V=255;// 1048576;
const int YYPQ=1;

//void qread(auto &sum){
//    sum=0;
//    auto f=sum+1;
//    char ch=getchar();
//    while(ch<'0' || ch>'9'){if(ch=='-') f=-1;ch=getchar();}
//    while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-48;ch=getchar();}
//    sum*=f;
//    return;
//}
//
//void qp(auto x){
//    if(x>9) qp(x/10);
//    putchar(x%10+48);
//    return;
//}
//void qpp(auto x){
//    if(x<0) x=-x,putchar('-');
//    qp(x);
//    return;
//}

int n,k;
int a[N];

int sum[N];

int f[N][N];
int ans;

//struct BITqwq{
//	int t[V+100];
//	void clear(){
//		for(int i=1;i<=V+YYPQ;i++) t[i]=0;
//		return;
//	}
//	
//	void update(int x,int del){
//		for(;x<=V;x+=lowbit(x)) t[x]+=del;
//		return;
//	}
//	int query(int x){
//		if(!x) return 0;
//		int res=0;
//		for(;x;x-=lowbit(x)) res+=t[x];
//		return res;
//	}
//}BIT;

//bool ss[V+100];
unordered_map<int,bool>ss;

int main(){
//    freopen("xor.in","r",stdin);
    freopen("xor5.in","r",stdin);
    freopen("xor.out","w",stdout);

	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum[i]=sum[i-1]^a[i];
	
	int tn=0;
	for(int i=1;i<=n;i++){
//		for(int j=0;j<i;j++){
//		BIT.clear();
//		for(int j=0;j<=V;j++) ss[j]=0;
		ss.clear();
		for(int j=i-1;~j;j--){
//			f[i+1][j]=max(f[i+1][j],f[i][j]);
			f[i+1][j]=max(f[i+1][j],f[i][j]);
			
//			if(sum[i]^sum[j-1]==k) f[i+1][i]=max(f[i+1][i],f[i][j]+1);
//			if((sum[i]^sum[j-1])==k) f[i+1][i]=max(f[i+1][i],f[i][j]+1);
//			int s=sum[i]^sum[j-1];

//			for(int p=j;p<i;p++){
//				tn++;
//				int s=sum[i]^sum[p];
//				if(s==k) f[i+1][i]=max(f[i+1][i],f[i][j]+1);
//			}

//			bool bbb=0;
//			for(int p=j;p<i;p++){
//				if((sum[i]^sum[p])==k){
//					bbb=1;
//					break;
//				}
//			}
//			if(bbb) f[i+1][i]=max(f[i+1][i],f[i][j]+1);
			
//			ss[sum[i]]=1;
			ss[sum[j]]=1;
			if(ss[k^sum[i]]) f[i+1][i]=max(f[i+1][i],f[i][j]+1);
			tn++;
			
//			cout<<"1111\n";
//			cout<<"now:: "<<i<<" "<<j<<"\n";
//			cout<<((k^sum[i])-1)<<" "<<(k^sum[i])<<"\n";
//			if((k^sum[i])>=0){
//				f[i+1][i]=max(f[i+1][i],BIT.query((k^sum[i])+YYPQ)-BIT.query((k^sum[i])-1+YYPQ)+1);
//				BIT.update(sum[i]+YYPQ,f[i+1][i]);
//				f[i+1][i]=max(f[i+1][i],ss[(k^sum[i])+YYPQ]+1);
//				ss[sum[i]+YYPQ]=max(ss[sum[i]+YYPQ],f[i+1][i]);
//			}

//			ss[sum[i]]=1;
//			if(ss[(k^sum[i])]) f[i+1][i]=max(f[i+1][i],f[i][j]+1);
			
//			cout<<"1111\n";
			
		}
	}
//	printf("%d\n",tn);
	
//	for(int i=0;i<=n;i++) ans=max(ans,f[n+1][i]);
	for(int i=1;i<=n+1;i++){
		for(int j=0;j<i;j++) ans=max(ans,f[i][j]);// ,cout<<f[i][j]<<" ";
//		cout<<"\n";
	}
	printf("%d\n",ans);
    return 0;
}
// 61	22	D:\GD-J01476\xor\xor.cpp	[Warning] suggest parentheses around comparison in operand of '^' [-Wparentheses]
// 10:02 for(int i=0;i<=n;i++) ans=max(ans,f[i+1][i]);
// Process exited after 0.129 seconds with return value 3221225477
*/
/*
from: cetime.cpp
#include<bits/stdc++.h>

typedef int IT;
typedef long long LL;
typedef __int128 int128;
typedef double DB;

#define pb push_back
#define fst first
#define sec second
#define psh push
#define PII pair<IT,IT>
#define PLI pair<LL,IT>
#define lowbit(x) ((x)&(-x))

using namespace std;

const int N=5e5+10;
//const int N=1e3+10;

//void qread(auto &sum){
//    sum=0;
//    auto f=sum+1;
//    char ch=getchar();
//    while(ch<'0' || ch>'9'){if(ch=='-') f=-1;ch=getchar();}
//    while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-48;ch=getchar();}
//    sum*=f;
//    return;
//}
//
//void qp(auto x){
//    if(x>9) qp(x/10);
//    putchar(x%10+48);
//    return;
//}
//void qpp(auto x){
//    if(x<0) x=-x,putchar('-');
//    qp(x);
//    return;
//}

int n,k;
int a[N];

int sum[N];

LL f[3][N];
int cur;
LL ans;

int main(){
//    freopen("xor.in","r",stdin);
    freopen("xor6.in","r",stdin);
    freopen("xor.out","w",stdout);

	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum[i]=sum[i-1]^a[i];
	
	int tn=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			f[cur^1][j]=max(f[cur^1][j],f[cur][j]);
//			if(sum[i]^sum[j-1]==k) f[i+1][i]=max(f[i+1][i],f[i][j]+1);
//			if((sum[i]^sum[j-1])==k) f[i+1][i]=max(f[i+1][i],f[i][j]+1);
//			int s=sum[i]^sum[j-1];
			for(int p=j;p<i;p++){
				tn++;
				int s=sum[i]^sum[p];
				if(s==k) f[cur^1][i]=max(f[cur^1][i],f[cur][j]+1);
			}
		}
		cur^=1;
	}
//	printf("%d\n",tn);
	
//	for(int i=0;i<=n;i++) ans=max(ans,f[n+1][i]);
//	for(int i=1;i<=n+1;i++){
//		for(int j=0;j<i;j++) ans=max(ans,f[i][j]);// ,cout<<f[i][j]<<" ";
////		cout<<"\n";
//	}
	for(int i=0;i<=n;i++) ans=max(ans,f[cur][i]);
	printf("%lld\n",ans);
    return 0;
}
// 61	22	D:\GD-J01476\xor\xor.cpp	[Warning] suggest parentheses around comparison in operand of '^' [-Wparentheses]
// 10:02 for(int i=0;i<=n;i++) ans=max(ans,f[i+1][i]);
*/
/*
from: xor.cpp
int main(){
	cout<<(2^3)<<"\n";
	cout<<(1^3)<<"\n";
	cout<<(1^2)<<"\n";
    return 0;
}
*/
/*
dp.cpp
#include<bits/stdc++.h>

typedef int IT;
typedef long long LL;
typedef __int128 int128;
typedef double DB;

#define pb push_back
#define fst first
#define sec second
#define psh push
#define PII pair<IT,IT>
#define PLI pair<LL,IT>
#define lowbit(x) ((x)&(-x))

using namespace std;

//const int N=5e5+10;
const int N=1e3+10;

//void qread(auto &sum){
//    sum=0;
//    auto f=sum+1;
//    char ch=getchar();
//    while(ch<'0' || ch>'9'){if(ch=='-') f=-1;ch=getchar();}
//    while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-48;ch=getchar();}
//    sum*=f;
//    return;
//}
//
//void qp(auto x){
//    if(x>9) qp(x/10);
//    putchar(x%10+48);
//    return;
//}
//void qpp(auto x){
//    if(x<0) x=-x,putchar('-');
//    qp(x);
//    return;
//}

int n,k;
int a[N];

int sum[N];

int f[N][N];
int ans;

int main(){
//    freopen("xor.in","r",stdin);
    freopen("xor3.in","r",stdin);
    freopen("xor.out","w",stdout);

	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum[i]=sum[i-1]^a[i];
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			f[i+1][j]=max(f[i+1][j],f[i][j]);
//			if(sum[i]^sum[j-1]==k) f[i+1][i]=max(f[i+1][i],f[i][j]+1);
//			if((sum[i]^sum[j-1])==k) f[i+1][i]=max(f[i+1][i],f[i][j]+1);
//			int s=sum[i]^sum[j-1];
			int s=sum[i]^sum[j];
			if(s==k) f[i+1][i]=max(f[i+1][i],f[i][j]+1);
		}
	}
	
	for(int i=0;i<=n;i++) ans=max(ans,f[i+1][i]);
	printf("%d\n",ans);
    return 0;
}
// 61	22	D:\GD-J01476\xor\xor.cpp	[Warning] suggest parentheses around comparison in operand of '^' [-Wparentheses]
*/
/*
cetime2.cpp
#include<bits/stdc++.h>

typedef int IT;
typedef long long LL;
typedef __int128 int128;
typedef double DB;

#define pb push_back
#define fst first
#define sec second
#define psh push
#define PII pair<IT,IT>
#define PLI pair<LL,IT>
#define lowbit(x) ((x)&(-x))

using namespace std;

//const int N=5e5+10;
//const int N=1e3+10,V=255;// 1048576;
const int N=5e5+10;// ,V=255;// 1048576;
//const int YYPQ=1;

//void qread(auto &sum){
//    sum=0;
//    auto f=sum+1;
//    char ch=getchar();
//    while(ch<'0' || ch>'9'){if(ch=='-') f=-1;ch=getchar();}
//    while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-48;ch=getchar();}
//    sum*=f;
//    return;
//}
//
//void qp(auto x){
//    if(x>9) qp(x/10);
//    putchar(x%10+48);
//    return;
//}
//void qpp(auto x){
//    if(x<0) x=-x,putchar('-');
//    qp(x);
//    return;
//}

int n,k;
int a[N];

int sum[N];

//int f[N][N];
LL f[3][N];
int cur;
LL ans;

//struct BITqwq{
//	int t[V+100];
//	void clear(){
//		for(int i=1;i<=V+YYPQ;i++) t[i]=0;
//		return;
//	}
//	
//	void update(int x,int del){
//		for(;x<=V;x+=lowbit(x)) t[x]+=del;
//		return;
//	}
//	int query(int x){
//		if(!x) return 0;
//		int res=0;
//		for(;x;x-=lowbit(x)) res+=t[x];
//		return res;
//	}
//}BIT;

//bool ss[V+100];
unordered_map<int,bool>ss;

int main(){
//    freopen("xor.in","r",stdin);
    freopen("xor6.in","r",stdin);
    freopen("xor.out","w",stdout);

	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum[i]=sum[i-1]^a[i];
	
	int tn=0;
	for(int i=1;i<=n;i++){
//		for(int j=0;j<i;j++){
//		BIT.clear();
//		for(int j=0;j<=V;j++) ss[j]=0;
		ss.clear();
		for(int j=i-1;~j;j--){
//			f[i+1][j]=max(f[i+1][j],f[i][j]);
			f[cur^1][j]=max(f[cur^1][j],f[cur][j]);
			
//			if(sum[i]^sum[j-1]==k) f[i+1][i]=max(f[i+1][i],f[i][j]+1);
//			if((sum[i]^sum[j-1])==k) f[i+1][i]=max(f[i+1][i],f[i][j]+1);
//			int s=sum[i]^sum[j-1];

//			for(int p=j;p<i;p++){
//				tn++;
//				int s=sum[i]^sum[p];
//				if(s==k) f[i+1][i]=max(f[i+1][i],f[i][j]+1);
//			}

//			bool bbb=0;
//			for(int p=j;p<i;p++){
//				if((sum[i]^sum[p])==k){
//					bbb=1;
//					break;
//				}
//			}
//			if(bbb) f[i+1][i]=max(f[i+1][i],f[i][j]+1);
			
//			ss[sum[i]]=1;
			ss[sum[j]]=1;
			if(ss[k^sum[i]]) f[cur^1][i]=max(f[cur^1][i],f[cur][j]+1);
			tn++;
			
//			cout<<"1111\n";
//			cout<<"now:: "<<i<<" "<<j<<"\n";
//			cout<<((k^sum[i])-1)<<" "<<(k^sum[i])<<"\n";
//			if((k^sum[i])>=0){
//				f[i+1][i]=max(f[i+1][i],BIT.query((k^sum[i])+YYPQ)-BIT.query((k^sum[i])-1+YYPQ)+1);
//				BIT.update(sum[i]+YYPQ,f[i+1][i]);
//				f[i+1][i]=max(f[i+1][i],ss[(k^sum[i])+YYPQ]+1);
//				ss[sum[i]+YYPQ]=max(ss[sum[i]+YYPQ],f[i+1][i]);
//			}

//			ss[sum[i]]=1;
//			if(ss[(k^sum[i])]) f[i+1][i]=max(f[i+1][i],f[i][j]+1);
			
//			cout<<"1111\n";
			
		}
		cur^=1;
	}
//	printf("%d\n",tn);
	
	for(int i=0;i<=n;i++) ans=max(ans,f[cur][i]);
//	for(int i=1;i<=n+1;i++){
//		for(int j=0;j<i;j++) ans=max(ans,f[i][j]);// ,cout<<f[i][j]<<" ";
////		cout<<"\n";
//	}
	printf("%lld\n",ans);
    return 0;
}
// 61	22	D:\GD-J01476\xor\xor.cpp	[Warning] suggest parentheses around comparison in operand of '^' [-Wparentheses]
// 10:02 for(int i=0;i<=n;i++) ans=max(ans,f[i+1][i]);
// Process exited after 0.129 seconds with return value 3221225477
*/
/*
try(the correct sol.cpp
#include<bits/stdc++.h>

typedef int IT;
typedef long long LL;
typedef __int128 int128;
typedef double DB;

#define pb push_back
#define fst first
#define sec second
#define psh push
#define PII pair<IT,IT>
#define PLI pair<LL,IT>
#define lowbit(x) ((x)&(-x))

using namespace std;

//const int N=5e5+10;
const int N=1e3+10,V=255;// 1048576;

int n,k;
int a[N];

int sum[N];

//int f[N][N];
LL f[3];// [N];
int cur;
LL ans;

unordered_map<int,bool>ss;

int main(){
//    freopen("xor.in","r",stdin);
    freopen("xor1.in","r",stdin);
    freopen("xor(2).out","w",stdout);
//    freopen("xor.out","w",stdout);

	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum[i]=sum[i-1]^a[i];
	
	for(int i=1;i<=n;i++){
		f[cur^1]=max(f[cur^1],f[cur]);
		ss[sum[i]]=1;
		if(ss[k^sum[i]]) f[cur^1]=max(f[cur^1],f[cur]+1);
		printf("%lld ",f[cur]);
		cur^=1;
	}putchar('\n'),putchar('\n');
	
	ans=f[cur];
	printf("%lld\n",ans);
    return 0;
}
*/
