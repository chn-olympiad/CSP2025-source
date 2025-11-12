#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int T,n,m[7];
struct ss{
	int a,b,c;
}a[maxn];
bool cmp(const ss x,const ss y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		int sum=0,cnta=0;
		if(n==2){
			m[1]=a[1].a+a[2].b;m[2]=a[1].a+a[2].c;
			m[3]=a[1].b+a[2].a;m[4]=a[1].b+a[2].c;
			m[5]=a[1].c+a[2].a;m[6]=a[1].c+a[2].b;
			for(int i=1;i<=6;i++){
				sum=max(sum,m[i]);
			}
			cout<<sum<<endl;
			continue;
		}
		sort(a+1,a+n+1,cmp);
		if(a[1].b==0&&a[1].c==0){
			for(int i=1;i<n/2;i++){
				sum+=a[i].a;
			}
			cout<<sum<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i].a>a[i].b and cnta<n/2){
				sum+=a[i].a;
				cnta++;
			}
			else{
				sum+=a[i].b;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
