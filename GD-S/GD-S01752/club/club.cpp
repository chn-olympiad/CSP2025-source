#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
ll n,Q,suma=0,sumb=0,sumc=0,ans=0;
struct mem{
	int id,a,b,c;
	char chos;
}a[N];
void init(){
	suma=0;
	sumb=0;
	sumc=0;
	ans=0;
	for (int i=1;i<N;i++){
		a[i].a=a[i].b=a[i].c=0;
		a[i].id=0;
		a[i].chos='h';
	}
	return ;
}
bool cmpa(mem al,mem b){
	return al.a>b.a;
}
bool cmpb(mem al,mem bl){
	return al.b>bl.b;
}
bool cmpc(mem al,mem b){
	return al.c>b.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>Q;
	while(Q--){
		cin>>n;
		if (n==2){
			int a1,a2,a3;
			int b1,b2,b3;
			cin>>a1>>a2>>a3;
			cin>>b1>>b2>>b3;
			int ans1=a1+max(b2,b3),ans2=max(b1,b3)+a2,ans3=max(b1,b2)+a3;
			cout<<max(ans1,max(ans3,ans2))<<endl;
			continue;
		}else if (n==4){
			for (int i=1;i<=n;i++){
				
				cin>>a[i].a>>a[i].b>>a[i].c;
				
			}
			int ans1=0,ans2=0,ans3=0;
			sort(a+1,a+1+n,cmpa);
			for (int i=1;i<=2;i++){
				ans1=ans1+a[i].a;
			}
			ans1=ans1+max(a[3].b,a[3].c)+max(a[4].b,a[4].c);
			sort(a+1,a+1+n,cmpb);
			for (int i=1;i<=2;i++){
				ans1=ans1+a[i].b;
			}
			ans2=ans2+max(a[3].a,a[3].c)+max(a[4].a,a[4].c);
			sort(a+1,a+1+n,cmpb);
			for (int i=1;i<=2;i++){
				ans1=ans1+a[i].c;
			}
			ans3=ans3+max(a[3].b,a[3].a)+max(a[4].b,a[4].a);
			cout<<max(ans1,max(ans2,ans3));
		}
		init();
		for (int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].id=i;
			a[i].chos='h';
		}
		sort(a+1,a+1+n,cmpa);
		for (int i=1;i<=n/2;i++){
			ans+=a[i].a;
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 
//Ren5Jie4Di4Ling5%
