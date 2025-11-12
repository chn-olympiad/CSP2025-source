//inpresation111 's Code
#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using  namespace std;
int t;
int n,cnta,cntb,cntc,ans;
struct Node{
	int a,b,c;
}a[100001];
bool  cmp(Node n1,Node n2){
	int l1=max(n1.a,max(n1.b,n1.c));
	int r1=max(n2.a,max(n2.b,n2.c));
	int l2,r2;
	if(l1==n1.a){
		l2=max(n1.b,n1.c);
	}if(l1==n1.b){
		l2=max(n1.a,n1.c);
	}if(l1==n1.c){
		l2=max(n1.b,n1.a);
	}
	if(r1==n2.a){
		r2=max(n2.b,n2.c);
	}if(r1==n2.b){
		r2=max(n2.a,n2.c);
	}if(r1==n2.c){
		r2=max(n2.b,n2.a);
	}
	return (l1-l2)>(r1-r2);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cnta=0;
		cntb=0;
		cntc=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			int flaga=0,flagb=0,flagc=0;
			if((max(a[i].a,max(a[i].b,a[i].c))==a[i].a)&&((cnta+1)<=(n/2))){
				ans+=a[i].a;
				cnta++;
				flaga=1;
			}else if((max(a[i].a,max(a[i].b,a[i].c))==a[i].b)&&((cntb+1)<=(n/2))){
				ans+=a[i].b;
				cntb++;
				flagb=1;
			}else if((max(a[i].a,max(a[i].b,a[i].c))==a[i].c)&&((cntc+1)<=(n/2))){
				ans+=a[i].c;
				cntc++;
				flagc=1;
			}else if((max(a[i].a,max(a[i].b,a[i].c))==a[i].c)&&(cntc>=(n/2))) {
				if(max(a[i].a,a[i].b)==a[i].a){
					cnta++;
					ans+=a[i].a;
				}else{
					cntb++;
					ans+=a[i].b;
				}
			}else if((max(a[i].a,max(a[i].b,a[i].c))==a[i].b)&&(cntb>=(n/2))) {
				if(max(a[i].a,a[i].c)==a[i].a){
					cnta++;
					ans+=a[i].a;
				}else{
					cntc++;
					ans+=a[i].c;
				}
			}else if((max(a[i].a,max(a[i].b,a[i].c))==a[i].a)&&(cnta>=(n/2))) {
				if(max(a[i].c,a[i].b)==a[i].c){
					cntc++;
					ans+=a[i].c;
				}else{
					cntb++;
					ans+=a[i].b;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
