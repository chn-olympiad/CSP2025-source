#include<bits/stdc++.h> 
using namespace std;
struct T{
	int a,b,c,mx,ma;
	bool b1=0;
}a[100001];
bool cmpa(T x,T y){
	if(x.b1==0)
		return x.a>y.a;
	return 0;
}
bool cmpb(T x,T y){
	if(x.b1==0)
		return x.b>y.b;
	return 0;
}
bool cmpc(T x,T y){
	if(x.b1==0)
		return x.c>y.c;
	return 0;
}
bool cmpmx(T x,T y){
	return x.mx>y.mx;
}
int n,t,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		n=0;
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].mx=max(a[i].a,max(a[i].b,a[i].c));
			if(a[i].mx==a[i].a){
				a[i].ma=1;
			}
			else if(a[i].mx==a[i].b){
				a[i].ma=2;
			}
			else if(a[i].mx==a[i].c){
				a[i].ma=3;
			}
		//	cout<<a[i].ma<<endl;
		}	
		
		sort(a+1,a+n+1,cmpmx);
		int a1=0,b2=0,c1=0;
		for (int i=1;i<=n;i++){
			if(a[i].ma==1 && a1<n/2){
				ans+=a[i].mx;
				a[i].b1=1;
				a1++;
			}
			else if(a[i].ma==2 && b2<n/2){
				ans+=a[i].mx;
				a[i].b1=1;
				b2++;
			}	
			else if(a[i].ma==3 && c1<n/2){
				ans+=a[i].mx;
				a[i].b1=1;
				c1++;
			}	
				
		}
		//sort(a+1,a+n+1,cmpa);
		for (int i=1;i<=n;i++){
			
			if(a[i].b1==0){
				if(a[i].ma==1 && (b2<=n/2 || c1<=n/2)){
					
					if(a[i].b<a[i].c){
						ans+=a[i].c;
						a[i].b1=1;
						c1++;
					}
					else{
						ans+=a[i].b;
						a[i].b1=1;
						b2++;
					}
					
				}
				 if(a[i].ma==2 && (a1<=n/2 || c1<=n/2)){
					if(a[i].a<a[i].c){
						ans+=a[i].c;
						a[i].b1=1;
						c1++;
					}
					else{
						ans+=a[i].a;
						a[i].b1=1;
						a1++;
					}
				}	
				else if(a[i].ma==3 && (a1<=n/2 || b2<=n/2)){
				if(a[i].b<a[i].b){
					ans+=a[i].b;
						a[i].b1=1;
						b2++;
					}
					else{
						ans+=a[i].a;
						a[i].b1=1;
						a1++;
					}
				}	
			}
			
		}
		cout<<ans<<endl;
		for (int i=1;i<=n;i++){
			ans=0;
			a[i].a=0;
			a[i].b=0;
			a[i].ma=0;
			a[i].mx=0;
			a[i].b1=0;
		}
	}
	return 0;
}
