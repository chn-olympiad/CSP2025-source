#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,P=998244353;
long long n,m,x[N],y,c=1,t,a[N],b[N],h,k[N],g,j;
string s;
struct no{
	long long a,b,c;
}d[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(s[i-1]=='1'){
			for(int j=1;j<=n;j++){
				if(a[i]<=h){
					b[i]=j;
					break;
				}
			}
			if(b[i]==0)b[i]=n-1;
			y+=b[i]; 
			c*=b[i];
			c%=P;
		}else{
			h++;
		}
	}
	cout<<c-y;
	return 0;
}
