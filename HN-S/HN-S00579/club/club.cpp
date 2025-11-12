#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int g[N],h[N],k[N];
int t,n,gl,hl,kl,sum;
struct st{
	int c1,c2,c3,b;
}a[N];
bool cmp(st x,st y){
    if(x.c1==y.c1)return x.c2>y.c2;
	else return x.c1>y.c1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int z=1;z<=t;z++){
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)cout<<"!@"<<a[i].c1<<" "<<a[i].c2<<" "<<a[i].c3<<endl; 
		for(int i=1;i<=n;i++){
			if(a[i].c1==max(max(a[i].c1,a[i].c3),max(a[i].c2,a[i].c3))){
				gl++;
				g[gl]=a[i].c1;
				sum+=a[i].c1;
				cout<<"#"<<a[i].c1<<endl;
				a[i].b=1;
			}
			if(hl<n/2&&a[i].b!=1&&a[i].c2==max(max(a[i].c1,a[i].c3),max(a[i].c2,a[i].c3))){
				hl++;
				h[hl]=a[i].c2;
				sum+=a[i].c2;
				cout<<"#"<<a[i].c2<<endl;
				a[i].b=1;
			}
			if(kl<n/2&&a[i].b!=1&&a[i].c3==max(max(a[i].c1,a[i].c3),max(a[i].c2,a[i].c3))){
				kl++;
				k[kl]=a[i].c3;
				cout<<"#"<<a[i].c3<<endl;
				sum+=a[i].c3;
			}
		}
		cout<<sum<<endl;
	}
}  
