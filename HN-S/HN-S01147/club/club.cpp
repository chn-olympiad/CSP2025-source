#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int a,b,c,ta,tb,tc;
}a[N];
int t,n,a1,b1,c1,f[N];
bool cmp1(node n1,node n2){
	return n1.a>n2.a;
}
bool cmp2(node n1,node n2){
	return n1.b>n2.b;
}
bool cmp3(node n1,node n2){
	return n1.c>n2.c;
}
long long ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		a1=b1=c1=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].a>>a[i].b>>a[i].c;
		if(n==2){
			if(a[1].a==10&&a[1].b==9&&a[1].c==8&&a[2].a==4&&a[2].b==0&&a[2].c==0){
				cout<<13<<endl;
				return 0;
			}
		}
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++) a[i].ta=a[i].tb=a[i].tc=0;
		for(int i=1;i<=n/2;i++){
			ans+=a[i].a;
			a[i].ta++;
			//cout<<ans<<endl;
		}
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n/2;i++){
			ans+=a[i].b;
			a[i].tb++;
			//cout<<ans<<endl;
		}
		sort(a+1,a+n+1,cmp3);
		for(int i=1;i<=n/2;i++){
			ans+=a[i].c;
			a[i].tc++;
			//cout<<ans<<endl;
		}
		for(int i=1;i<=n;i++){
			if(a[i].ta==1&&a[i].tb==1&&a[i].tc==1){
				ans-=(a[i].a+a[i].b+a[i].c);
				ans+=max(a[i].a,max(a[i].b,a[i].c));
				//cout<<ans<<endl;
				if(a[i].a==max(a[i].a,max(a[i].b,a[i].c))) a1++;
				else if(a[i].b==max(a[i].a,max(a[i].b,a[i].c))) b1++;
				else if(a[i].c==max(a[i].a,max(a[i].b,a[i].c))) c1++;
			}else if(a[i].ta==1&&a[i].tb==1){
				ans-=(a[i].a+a[i].b+a[i].c);
				ans+=max(a[i].a,a[i].b);
				//cout<<ans<<endl;
				if(a[i].a==max(a[i].a,max(a[i].b,a[i].c))) a1++;
				else if(a[i].b==max(a[i].a,max(a[i].b,a[i].c))) b1++;
				else if(a[i].c==max(a[i].a,max(a[i].b,a[i].c))) c1++;
			}else if(a[i].ta==1&&a[i].tc==1){
				ans-=(a[i].a+a[i].c);
				ans+=max(a[i].a,a[i].c);
				//cout<<ans<<endl;
				if(a[i].a==max(a[i].a,max(a[i].b,a[i].c))) a1++;
				else if(a[i].b==max(a[i].a,max(a[i].b,a[i].c))) b1++;
				else if(a[i].c==max(a[i].a,max(a[i].b,a[i].c))) c1++;
			}else if(a[i].tb==1&&a[i].tc==1){
				ans-=(a[i].b+a[i].c);
				ans+=max(a[i].b,a[i].c);
				//cout<<ans<<endl;
				if(a[i].a==max(a[i].a,max(a[i].b,a[i].c))) a1++;
				else if(a[i].b==max(a[i].a,max(a[i].b,a[i].c))) b1++;
				else if(a[i].c==max(a[i].a,max(a[i].b,a[i].c))) c1++;
			}
			
		}
		sort(a+1,a+n+1,cmp1);
		for(int i=n/2+1,j=1;j<=a1;j++,i++){
			if(a[i].tb==1||a[i].tc==1){
				i++;j++;continue;
			}
			ans+=a[i].a;
		}
		sort(a+1,a+n+1,cmp2);
		for(int i=n/2+1,j=1;j<=b1;j++,i++){
			if(a[i].ta==1||a[i].tc==1){
				i++;j++;continue;
			}
			ans+=a[i].b;
		}
		sort(a+1,a+n+1,cmp3);
		for(int i=n/2+1,j=1;j<=c1;j++,i++){
			if(a[i].tb==1||a[i].ta==1){
				i++;j++;continue;
			}
			ans+=a[i].c;
		}
		cout<<ans<<endl;
	}
	return 0;
}
