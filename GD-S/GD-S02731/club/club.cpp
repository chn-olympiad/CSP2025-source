#include<bits/stdc++.h>
using namespace std;
struct hhh{
			int a=0;
			int b=0;
			int c=0;
			int k=0;
}a[10005];
bool cmp(hhh a,hhh b){
	return a.a<b.a;
}
bool cmp1(hhh a,hhh b){
	return a.b<b.b;
}
bool cmp2(hhh a,hhh b){
	return a.c<b.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		hhh a1[5005];
		int a2=0,c2=0,b2=0;
		int ans=0;
		int n;
		cin>>n;
		for(int i = 0;i<n;i++){
			a1[i].k = i;
		}
		for(int i =0;i<n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		for(int i =0;i<n;i++){
			if(a[i].a==a[i].b||a[i].a==a[i].c||a[i].b==a[i].c){
				if(a[i].a==a[i].b&&a[i].a==a[i].c){
					if(a2>b2){
						a1[i].a+=a[i].a;
						a2++;
					}
					else if(a2>c2){
						a1[i].a+=a[i].a;
						a2++;
					}
					else if(b2>c2){
						a1[i].b+=a[i].b;
						b2++;
					}
					else{
						a1[i].c+=a[i].c;
						c2++;
					}
				}
				else if(a[i].a==a[i].b){
					if(a2>b2){
						a1[i].a+=a[i].a;
						a2++;
					}
					else{
						a1[i].b+=a[i].b;
						b2++;
					}
				}
				else if(a[i].a==a[i].c){
					if(a2>c2){
						a1[i].a+=a[i].a;
						a2++;
					}
					else{
						a1[i].c+=a[i].c;
						c2++;
					}
				}
				else{
					if(b2>c2){
						a1[i].b+=a[i].b;
						b2++;
					}
					else{
						a1[i].c+=a[i].c;
						c2++;
					}
				}
			}
			else if(a[i].a>a[i].b){
				if(a[i].a>a[i].c){
					a1[i].a+=a[i].a;
					a2++;
				}
				else{
					a1[i].c+=a[i].c;
					c2++;
				}
			}
			else{
				if(a[i].c>a[i].b){
					a1[i].c+=a[i].c;
					c2++;
				}
				else{
					a1[i].b+=a[i].b;
					b2++;
				}
			}
		}
		int k=0;
		int k1=0;
		if(a2>n/2){
			sort(a1,a1+n,cmp);
			k=1;
			k1 = 1;
			for(int i = 0;i<a2-n/2;i++){
				if(a[a1[i].k].b>a1[a1[i].k].c){
					b2++;
					a1[i].a = 0;
					a1[i].b = a[a1[i].k].b;
				}
				else if(a[a1[i].k].b<a1[a1[i].k].c){
					c2++;
					a1[i].a = 0;
					a1[i].c = a[a1[i].k].c;
				}
				else{
					if(b2>c2){
						c2++;
						a1[i].a = 0;
						a1[i].c = a[a1[i].k].c;
					}
					else{
						b2++;
						a1[i].a = 0;
						a1[i].b = a[a1[i].k].b;
					}
				}
			}
		}
		if(b2>n/2){
			sort(a1,a1+n,cmp1);
			for(int i = 0;i<b2-n/2;i++){
				if(a[a1[i].k].c>a1[a1[i].k].a){
					c2++;
					a1[i].b = 0;
					a1[i].c = a[a1[i].k].c;
				}
				else if(a[a1[i].k].c<a1[a1[i].k].a&&k!=1){
					a2++;
					a1[i].b = 0;
					a1[i].a = a[a1[i].k].a;
				}
				else{
					if(c2>a2&&k!=1){
						a2++;
						a1[i].b = 0;
						a1[i].a = a[a1[i].k].a;
					}
					else{
						c2++;
						a1[i].b = 0;
						a1[i].c = a[a1[i].k].c;
					}
				}
			}
			k = 2;
		}
		if(c2>n/2){
			sort(a1,a1+n,cmp2);
			for(int i = 0;i<c2-n/2;i++){
				if(a[a1[i].k].b>a1[a1[i].k].a&&k!=2){
					b2++;
					a1[i].c = 0;
					a1[i].b = a[a1[i].k].b;
				}
				else if(a[a1[i].k].b<a1[a1[i].k].a&&k1!=1){
					a2++;
					a1[i].c = 0;
					a1[i].a = a[a1[i].k].a;
				}
				else{
					if(b2>a2&&k1!=1){
						a2++;
						a1[i].c = 0;
						a1[i].a = a[a1[i].k].a;
					}
					else{
						if(k!=2){
							b2++;
							a1[i].c = 0;
							a1[i].b = a[a1[i].k].b;
						}
					}
				}
			}
		}
		for(int i = 0;i<n;i++){
			ans+=a1[i].a+a1[i].b+a1[i].c;
		}
		cout<<ans<<endl;
	}
}
