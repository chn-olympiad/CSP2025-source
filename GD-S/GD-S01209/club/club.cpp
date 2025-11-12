#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int q=0,w=0,e=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>a[i].b&&a[i].a>a[i].c)q++;
			if(a[i].b>a[i].a&&a[i].b>a[i].c)w++;
			if(a[i].c>a[i].b&&a[i].c>a[i].a)e++;
		}
		if(n==2){
			int t1=a[1].a+a[2].b;
			int t2=a[1].a+a[2].c;
			int t3=a[1].b+a[2].a;
			int t4=a[1].b+a[2].c;
			int t5=a[1].c+a[2].a;
			int t6=a[1].c+a[2].b;
			t1=max(t1,t2);
			t1=max(t1,t3);
			t1=max(t1,t4);
			t1=max(t1,t5);
			t1=max(t1,t6);
			cout<<t1<<"\n";
		}
		if(q<=n/2&&w<=n/2&&e<=n/2){
			int ans=0;
			for(int i=1;i<=n;i++){
			}
			cout<<ans<<"\n";
		}
		if(q==n){
			int ans=0;
			int b[100005];
			for(int i=1;i<=n;i++){
				b[i]=a[i].a;
			}
			sort(b+1,b+1+n);
			for(int i=n/2+1;i<=n;i++)ans+=b[i];
			cout<<ans<<"\n";
			
		}
	} 
	return 0;
} 
/*
6
5 4 4
5 4 4
6 3 1
7 1 1
1 5 3
4 1 1
*/
