#include<bits/stdc++.h>
using namespace std;
struct code{
	int a,b,c;
	int num=0;
}q[100100];
bool cmp(code x,code y){
	return x.num>y.num;
}
bool cmp1(code x,code y){
	return x.a>y.a;
}
bool cmp2(code x,code y){
	return x.b>y.b;
}
bool cmp3(code x,code y){
	if(x.a==y.a){
		if(x.b==y.b)return x.c>y.c;
		return x.b>y.b;
	}
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,a1=0,b1=0,c1=0;
		long long ans=0;
		int x=0,y=0,z=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>q[i].a>>q[i].b>>q[i].c;
			if(q[i].a!=0)x=1;
			if(q[i].b!=0)y=1;
			if(q[i].c!=0)z=1;
			q[i].num=q[i].a+q[i].b+q[i].c;
		}
		sort(q+1,q+n+1,cmp3);
		if(x+y+z<=1){
			for(int i=1;i<=n;i++){
				if(a1<n/2){
					ans+=q[i].a;
					a1++;
				}
				if(b1<n/2){
					ans+=q[i].b;
					b1++;
				}
				if(c1<n/2){
					ans+=q[i].c;
					c1++;
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		if(z==0){
			int maxa=0,maxb=0;
			for(int i=1;i<=n;i++){
				maxa=max(maxa,q[i].a);
				maxb=max(maxb,q[i].b);
			}
			if(maxa>maxb){
				sort(q+1,q+n+1,cmp1);
				for(int i=1;i<=n;i++){
					if(q[i].a>=q[i].b&&a1<n/2){
						a1++;
						ans+=q[i].a;
					}
					else{
						b1++;
						ans+=q[i].b;
					}
				}
			}
			else if(maxb>maxa){
				sort(q+1,q+n+1,cmp2);
				for(int i=1;i<=n;i++){
					if(q[i].b>=q[i].a&&b1<n/2){
						b1++;
						ans+=q[i].b;
					}
					else{
						a1++;
						ans+=q[i].a;
					}
				}
			}
			else{
				sort(q+1,q+n+1,cmp);
				for(int i=1;i<=n;i++){
					if(q[i].a>=q[i].b&&a1<n/2){
						a1++;
						ans+=q[i].a;
					}
					else{
						b1++;
						ans+=q[i].b;
					}
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			if(q[i].a>=q[i].b&&q[i].a>=q[i].c){
				if(i!=n&&q[i+1].b==0&&q[i+1].c==0){
					if(q[i].b>q[i].c){
						ans+=q[i].b;
						b1++;
					}
					else{
						ans+=q[i].c;
						c1++;
					}
					continue;
				}
				if(a1<n/2){
					ans+=q[i].a;
					a1++;
				}
			}
			if(q[i].b>=q[i].a&&q[i].b>=q[i].c){
				if(i!=n&&q[i+1].a==0&&q[i+1].c==0){
					if(q[i].a>q[i].c){
						ans+=q[i].a;
						a1++;
					}
					else{
						ans+=q[i].c;
						c1++;
					}
					continue;
				}
				if(b1<n/2){
					ans+=q[i].b;
					b1++;
				}
			}
			if(q[i].c>=q[i].b&&q[i].c>=q[i].a){
				if(i!=n&&q[i+1].a==0&&q[i+1].b==0){
					if(q[i].a>q[i].b){
						ans+=q[i].a;
						a1++;
					}
					else{
						ans+=q[i].b;
						b1++;
					}
					continue;
				}
				if(c1<n/2){
					ans+=q[i].c;
					c1++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

