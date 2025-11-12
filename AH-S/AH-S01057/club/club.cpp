#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int t;
int n;
struct A{
	int a,b,c,d,e,f,g;
};
bool cmp(A a,A b){
	return !(a.g>b.g);
}
A a[100010];
int b1[10];
int ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		b1[1]=b1[2]=b1[3]=0;
		ans=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			int c,d=-1,e=-2,f=-3,g,h,l,m;
			for(int k=1;k<=3;k++){
				cin>>c;
				if(c>d){
					f=e;l=h;e=d;h=g;d=c;g=k;
				}else if(c>e){
					f=e;l=h;e=c;h=k;
				}else{
					f=c;l=k;
				}
			}
			m=d-e;
			a[j]={d,e,f,g,h,l,m};
			b1[g]++;
		}
		int c=0,d=0;
		if(b1[1]>n/2) c=1;
		if(b1[2]>n/2) c=2;
		if(b1[3]>n/2) c=3;
		sort(a+1,a+n,cmp);
		for(int j=n;j>=1;j--){
			if(a[j].d==c){
				d++;
			}
			if(a[j].d==c&&d>n/2){
				ans+=a[j].b;
			}else{
				ans+=a[j].a;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
