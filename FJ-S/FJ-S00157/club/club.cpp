#include<bits/stdc++.h>
using namespace std;
int t,n,p,q,maxn;
struct no{
	int a,b,c;
}a[101001];
bool cmp(no x,no y){
	return x.a>y.a;
}
bool cm(no x,no y){
	return x.b>y.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int e=0,f=0,g=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			p+=a[i].a;
			q+=a[i].b;
		}
		if(p>=q){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n;i++){
				if(f<(n+1)/2){
					if(a[i].a>a[i].b||g>=(n+1)/2){
						e+=a[i].a;
						f++;
					}else{
						e+=a[i].b;
						g++;
					}
				}else e+=a[i].b;
			}
		}else{
			sort(a+1,a+n+1,cm);
			for(int i=1;i<=n;i++){
				if(g<(n+1)/2){
					if(a[i].b>a[i].a||f>=(n+1)/2){
						e+=a[i].b;
						g++;
					}else{
						e+=a[i].a;
						f++;
					}
				}else e+=a[i].a;
			}
		}
		cout<<e<<endl;
	}
	return 0;
} 
