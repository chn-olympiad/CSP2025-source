#include<bits/stdc++.h>
using namespace std;

struct node{
	int a,b,c;
	int na,nb,nc;
}a[100005];
int n;
int cal(int a,int b,int c){
	if(a>=b&&b>=c){
		return b;
	}
	if(c>=b&&b>=a){
		return b;
	}
	if(a>=c&&c>=b){
		return c;
	}
	if(b>=c&&c>=a){
		return c;
	}
	if(c>=a&&a>=b){
		return a;
	}
	if(b>=a&&a>=c){
		return a;
	}
}
bool cmp(node a,node b){
	return max(a.a,max(a.b,a.c))-cal(a.a,a.b,a.c)>max(b.a,max(b.b,b.c))-cal(b.a,b.b,b.c);
}
bool cmp2(node a,node b){
	return a.a-a.b>b.a-b.b;
}
int cnta=0,cntb=0,cntc=0;
int maxid(node a){
	int maxa=max(a.a,max(a.b,a.c));
	if(a.a==maxa){
		if(cnta==n/2){
			if(a.b>a.c){
				cntb++;
				return a.b;
			}else{
				cntc++;
				return a.c;
			}
		}else{
			cnta++;
			return a.a;
		}
	}
	if(a.b==maxa){
		if(cntb==n/2){
			if(a.a>a.c){
				cnta++;
				return a.a;
			}else{
				cntc++;
				return a.c;
			}
		}else{
			cntb++;
			return a.b;
		}
	}
	if(a.c==maxa){
		if(cntc==n/2){
			if(a.a>a.b){
				cnta++;
				return a.a;
			}else{
				cntb++;
				return a.b;
			}
		}else{
			cntc++;
			return a.c;
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		long long ans=0;
		cnta=0,cntb=0,cntc=0;
		cin>>n;
		bool flag1=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].c!=0){
				flag1=0;
			}
			// int maxa=min(a[i].a,min(a[i].b,a[i].c));
			// a[i].na=a[i].a-maxa;
			// a[i].nb=a[i].b-maxa;
			// a[i].nc=a[i].c-maxa;
		}
		if(flag1){
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a;
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=a[i].b;
			}
			cout<<ans<<"\n";
			continue;
		}
		sort(a+1,a+n+1,cmp);
		
		for(int i=1;i<=n;i++){
			ans+=maxid(a[i]);
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}