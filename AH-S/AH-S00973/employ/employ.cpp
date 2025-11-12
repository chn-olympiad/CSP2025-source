#include "iostream"
#include "cstdio"
#include "algorithm"
#include "string"
#include "cstring"
using namespace std;
#define MOD 998244353
int n,m,c[505],ans=0,a[505],flag=0;
string s;
int main(){
	freopen ("employ.in","r",stdin);
	freopen ("employ.out","w",stdout);
	scanf ("%d %d",&n,&m);
	cin >> s;
	for (int i=1;i<=n;i++){
		scanf ("%d",&c[i]);
		if (s[i-1]=='1') flag++;
		a[i]=i;
	}
	if (n>17 && flag==n){
		int anss=1ll;
		for (long long i=2ll;i<=n;i++){
			anss=(anss*i)%MOD;
		}
		printf ("%d\n",anss);
		return 0;
	}
	do{
		int sum=0,ss=0;
		for (int i=1;i<=n;i++){
			if (sum>=c[a[i]]) sum++;
			else if (s[i-1]=='0'){
				sum++;
			}
			else ss++;
		}
		if (ss>=m) ans=(ans+1ll)%MOD;
	}while (next_permutation(a+1,a+1+n));
	printf ("%d\n",ans);
	return 0;
}
