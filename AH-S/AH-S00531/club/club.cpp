#include<bits/stdc++.h>
using namespace std;
long long t;
long long n;
long long a[100005][10];
long long s[5];
long long b[100005];
long long len;
long long x1;
long long x2;
bool cmp(int one,int two){
	x1=x2=0;
	x1=a[one][a[one][4]]+a[two][a[two][5]];
	x2=a[one][a[one][5]]+a[two][a[two][4]];
	if(x1>x2)return 1;
	else return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof a);
		memset(s,0,sizeof s);
		memset(b,0,sizeof b);
		len=0;
		for(int i=1;i<=n;i++){
			int m=0;
			int mj=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>m){
					m=a[i][j];
					mj=j;
				}
			}
			a[i][4]=mj;
			s[mj]++;
			int m2=0;
			int mi2=0;
			for(int j=1;j<=3;j++){
				if(a[i][j]>m2&&j!=mj){
					m2=a[i][j];
					mi2=j;
				}
			}
			for(int j=1;j<=3;j++){
				if(j!=mj&&j!=mi2){
					a[i][6]=j;
					break;
				}
			}
			a[i][5]=mi2;
		}
		long long kk=0;
		long long ki=0;
		for(int i=1;i<=3;i++){
			if(s[i]>kk){
				kk=s[i];
				ki=i;
			}
		}
		if(kk>(n/2)){
			for(int i=1;i<=n;i++){
				if(a[i][4]==ki){
					b[++len]=i;
				}
			}
			sort(b+1,b+len+1,cmp);
			for(int i=n/2+1;i<=len;i++){
				a[b[i]][4]=a[b[i]][5];
			}
			long long sum=0;
			for(int i=1;i<=n;i++){
				sum+=a[i][a[i][4]];
			}
			cout<<sum<<'\n';
		}
		else{
			long long sum=0;
			for(int i=1;i<=n;i++){
				sum+=a[i][a[i][4]];
			}
			cout<<sum<<'\n';
		}
	}
	return 0;
}
