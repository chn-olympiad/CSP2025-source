#include <bits/stdc++.h>
using namespace std;
long long f[100005];
long long v[100005][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		long long x=0,y=0,z=0;
		long long ans=0;
		for(long long i=1;i<=n;i++){
			v[i][1]=0,v[i][2]=0,v[i][3]=0;
			f[i]=0;
			long long a,b,c;
			cin>>a>>b>>c;
			if(a>=b and a>=c) v[i][1]=1,x++;
			else if(b>=a and b>=c) v[i][2]=1,y++;
			else if(c>=a and c>=b) v[i][3]=1,z++;
			if(a<b) swap(a,b);
			if(a<c) swap(a,c);
			if(b<c) swap(b,c);
			ans+=a;
			f[i]=a-b;
		}
		if(x>n/2){
			vector<long long> vec(20005);
			for(long long i=1;i<=n;i++){
				if(v[i][1]==1){
					vec[f[i]]++;
				}
			}
			for(long long i=0;i<=20005;i++){
				if(x==n/2){
					break;
				}
				if(vec[i]>0){
					vec[i]--;
					ans-=i;
					i--;
					x--;
				}
			}
		}
		if(y>n/2){
			vector<long long> vec(20005);
			for(long long i=1;i<=n;i++){
				if(v[i][2]==1){
					vec[f[i]]++;
				}
			}
			for(long long i=0;i<=20005;i++){
				if(y==n/2){
					break;
				}
				if(vec[i]>0){
					vec[i]--;
					ans-=i;
					i--;
					y--;
				}
			}
		}
		if(z>n/2){
			vector<long long> vec(20005);
			for(long long i=1;i<=n;i++){
				if(v[i][3]==1){
					vec[f[i]]++;
				}
			}
			for(long long i=0;i<=20005;i++){
				if(z==n/2){
					break;
				}
				if(vec[i]>0){
					vec[i]--;
					ans-=i;
					i--;
					z--;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}