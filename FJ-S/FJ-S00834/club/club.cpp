#include<bits/stdc++.h>
using namespace std;
const int N=100005;
long long n,t,ans1,ans2,ans3;
bool f[N];
struct S{
	int a1,a2,a3;	
}a[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int z=1;z<=t;z++){
		ans1=0;
		ans2=0;
		ans3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1 >>a[i].a2 >>a[i].a3 ;
		}
		if(n==2){
			cout<<max(a[1].a1+a[2].a2,max(a[1].a1+a[2].a3,max(a[1].a2+a[2].a1,max(a[1].a2+a[2].a3,max(a[1].a3+a[2].a1,a[1].a3+a[2].a2)))));
			return 0;
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(a[i].a1 >a[j].a1 ){
					swap(a[i],a[j]);
				}
			}
		}
		for(int i=1;i<=n/2;i++){
			ans1+=a[i].a1 ;
			f[i]=1;
		}
		for(int i=n/2+1;i<=n;i++){
			if(a[i].a2 >a[i].a3 ){
				ans2+=a[i].a2;
				f[i]=1;	
			}
			else{
				ans3+=a[i].a3 ;
				f[i]=1;			
			}
		}
		cout<<ans1+ans2+ans3<<endl;;
	}
	return 0;
}
