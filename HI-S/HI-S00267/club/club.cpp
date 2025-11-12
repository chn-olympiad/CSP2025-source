#include <bits/stdc++.h>
using namespace std;
struct tx{
	int a,b,c;
};
tx a[100001];
int t,n,a1[100001],a2[100001],a3[100010],b,c,d,sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j].a>>a[j].b>>a[j].c;
			if(a[j].a>a[j].b && a[j].a>a[j].c){
				if(b<n/2){
					a1[++b]=a[j].a;
				}else{
					sort(a1+1,a1+b+1);
					a1[1]=max(a1[1],a[j].a);
				}
			}else if(a[j].b>a[j].a && a[j].b>a[j].c){
				if(c<n/2){
					a2[++c]=a[j].b;
				}else{
					sort(a2+1,a2+c+1);
					a2[1]=max(a2[1],a[j].b);
				}
			}else{
				if(d<n/2){
					a3[++d]=a[j].c;
				}else{
					sort(a3+1,a3+d+1);
					a3[1]=max(a3[1],a[j].c);
				}
			}
		}
		for(int j=1;j<=b;j++){
			sum+=a1[j];
			a1[j]=0;
		}
		for(int j=1;j<=c;j++){
			sum+=a2[j];
			a2[j]=0;
		}
		for(int j=1;j<=d;j++){
			sum+=a3[j];
			a3[j]=0;
		}
		cout<<sum<<endl;
		b=0,c=0,d=0,sum=0;
	}
	return 0;
}
