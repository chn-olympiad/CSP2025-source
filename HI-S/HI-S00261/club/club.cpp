#include<bits/stdc++.h>
using namespace std;
struct ch{
	long long a,b,c;
}a[1000005];
bool cmp(ch x,ch y){
	if(x.a+x.b+x.c==y.a+y.b+y.c){
		if(x.a==y.a){
		if(x.b==y.b){
			return x.c>y.c;	
		}
		return x.b>y.b;
		}
	}
	return x.a+x.b+x.c>y.a+y.b+y.c;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		long long n,w=0,z=0,m=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;		
		}
		sort(a+1,a+n+1,cmp);
		long long s=0;
		for(int i=1;i<=n;i++){
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
				if(w<n/2){
					w++;
					s+=a[i].a;	
				}
				else{
					if(a[i].b>=a[i].c){
						if(z<n/2){
							z++;
							s+=a[i].b;
						}else{
							m++;
							s+=a[i].c;
						}
					}else{
						if(m<n/2){
							m++;
							s+=a[i].c;
						}else{
							z++;
							s+=a[i].b;
						}
					}
				}
			}else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
				if(z<n/2){
					z++;
					s+=a[i].b;	
				}
				else{
					if(a[i].a>=a[i].c){
						if(w<n/2){
							w++;
							s+=a[i].a;
						}else{
							m++;
							s+=a[i].c;
						}
					}else{
						if(m<n/2){
							m++;
							s+=a[i].c;
						}else{
							w++;
							s+=a[i].a;
						}
					}
				}
			}else{
				if(m<n/2){
					m++;
					s+=a[i].c;	
				}
				else{
					if(a[i].b>=a[i].a){
						if(z<n/2){
							z++;
							s+=a[i].b;
						}else{
							w++;
							s+=a[i].a;
						}
					}else{
						if(w<n/2){
							m++;
							s+=a[i].a;
						}else{
							z++;
							s+=a[i].b;
						}
					}
				}
			}
		}
		cout<<s<<'\n';
	}
	return 0;//相信自己可以骗到分！
}

