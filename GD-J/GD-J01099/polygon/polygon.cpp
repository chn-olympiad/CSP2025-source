#\
i\
n\
c\
l\
u\
d\
e\
<\
b\
i\
t\
s\
/\
s\
t\
d\
c\
+\
+\
.\
h\
>
#\
d\
e\
f\
i\
n\
e\
 \
a\
k\
i\
o\
i\
 \
r\
e\
t\
u\
r\
n\
 \
0
//#define int long long
using namespace std;

const long long mod=998244353;
long long n,a[50001],dp[50002],ans[50002];

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	freopen("polygon4.in","r",stdin);
//	freopen("polygon4.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dp[0]=1;
	long long all=0;
	for(long long j=1;j<=n;j++){
		for(long long l=a[n]+1;l>a[n]+1-a[j];l--){
			dp[a[n]+1]+=dp[l];
			dp[a[n]+1]%=mod;
		}
		for(long long l=a[n]+1;l>=a[j];l--){
			dp[l]+=dp[l-a[j]];
			dp[l]%=mod;
		}
//		for(long long i=1;i<=a[n]+1;i++){
//			cout<<dp[i]<<" ";
//		} 
//		cout<<"\n";
		if(j>=2&&j<n){
			for(long long l=a[j+1]+1;l<=a[n]+1;l++){
//				cout<<"L:"<<l<<" a[j+1]:"<<a[j+1]<<" "<<dp[l]<<"\n";
				ans[j+1]+=dp[l];
				ans[j+1]%=mod;
			}
		}
	}
	for(long long i=1;i<=n;i++){
		all+=ans[i];
		all%=mod;
	}
	cout<<all;
	akioi;
}
/*
5
1 2 3 4 5

5
2 2 3 8 10
*/
