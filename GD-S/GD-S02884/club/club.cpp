#include<bits/stdc++.h>
using namespace std;
int t,n,cnta=0,cntb=0,cntc=0;
long long ans=0;
struct stu{
	int a,b,c,mx,m2x,mx1;
}st[100005];
bool cmp(stu s1 , stu s2){
	return s1.mx1>s2.mx1;
}
int main(){
//	Ren5Jie4Di4Ling5%
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t!=0){
		t--;
		cin>>n;
		cnta=0,cntb=0,cntc=0,ans=0;
		for(int i=1;i<=n;i++){
			cin>>st[i].a>>st[i].b>>st[i].c;
			st[i].mx=max(max(st[i].a,st[i].b),st[i].c);
			if(st[i].mx==st[i].a){
				st[i].m2x=max(st[i].b,st[i].c);
			}else if(st[i].mx==st[i].b){
				st[i].m2x=max(st[i].a,st[i].c);
			}else{
				st[i].m2x=max(st[i].a,st[i].b);
			}
			st[i].mx1=st[i].mx-st[i].m2x;
		}
		sort(st+1,st+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(st[i].mx==st[i].a && st[i].m2x==st[i].b){
				if(cnta<n/2){
					ans+=st[i].a;
					cnta++;
				}else{
					ans+=st[i].b;
					cntb++;
				}
				
			}else if(st[i].mx==st[i].a && st[i].m2x==st[i].c){
				if(cnta<n/2){
					ans+=st[i].a;
					cnta++;
				}else{
					ans+=st[i].c;
					cntc++;
				}
			}else if(st[i].mx==st[i].b && st[i].m2x==st[i].a){
				if(cntb<n/2){
					ans+=st[i].b;
					cntb++;
				}else{
					ans+=st[i].a;
					cnta++;
				}
			}else if(st[i].mx==st[i].b && st[i].m2x==st[i].c){
				if(cntb<n/2){
					ans+=st[i].b;
					cntb++;
				}else{
					ans+=st[i].c;
					cntc++;
				}
			}else if(st[i].mx==st[i].c && st[i].m2x==st[i].a){
				if(cntc<n/2){
					ans+=st[i].c;
					cntc++;
				}else{
					ans+=st[i].a;
					cnta++;
				}
			}else if(st[i].mx==st[i].c && st[i].m2x==st[i].b){
				if(cntc<n/2){
					ans+=st[i].c;
					cntc++;
				}else{
					ans+=st[i].b;
					cntb++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
