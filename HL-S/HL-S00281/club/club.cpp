#include<iostream>
#include<algorithm>
using namespace std;
struct d1{
	long long a,b;
};
struct d{
	d1 a,b,c;
	long long g;
};
int f[3];
d q[100010];
		int a[100010];
		bool cmp(int z,int x){
			return z>x;
		}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		f[1]=0;
		f[0]=0;
		f[2]=0;
		int n;
		cin>>n;
		int an=0;
		for(int i=0;i<n;i++){
			cin>>q[i].a.a>>q[i].b.a>>q[i].c.a;
			a[an]=q[i].a.a;
			an++;
		}
		sort(a,a+an,cmp);
		int ans=0;
		for(int i=0;i<n/2;i++){
			ans+=a[i];
		}
		cout<<ans<<endl;
	}
}
