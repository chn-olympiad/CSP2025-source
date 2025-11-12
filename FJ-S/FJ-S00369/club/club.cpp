#include<bits/stdc++.h>
using namespace std;
struct s {
	long long a,b,c;
} sco[3][100001];
int acnt,bcnt,ccnt;
bool acmp(s a,s b) {
	return min(a.a-a.b,a.a-a.c)>min(b.a-b.b,b.a-b.c);
}
bool bcmp(s a,s b) {
	return min(a.b-a.c,a.b-a.a)>min(b.b-b.c,b.b-b.a);
}
bool ccmp(s a,s b) {
	return min(a.c-a.b,a.c-a.a)>min(b.c-b.a,b.c-b.b);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		for(int i=1; i<=n; i++) {
			long long a,b,c;
			cin>>a>>b>>c;
			s sl;
			sl.a=a,sl.b=b,sl.c=c;
			if(a>=b&&a>=c) {
				sco[0][++acnt]=sl;
			}
			else if(b>a&&b>=c) {
				sco[1][++bcnt]=sl;
			}
			else if(c>a&&c>b) {
				sco[2][++ccnt]=sl;
			}
		}
		if(bcnt>n/2){
			sort(sco[1]+1,sco[1]+1+bcnt,bcmp);
			while(bcnt>n/2){
				if(sco[1][bcnt].a>sco[1][bcnt].c)sco[0][++acnt]=sco[1][bcnt];
				if(sco[1][bcnt].a<=sco[1][bcnt].c)sco[2][++ccnt]=sco[1][bcnt];
				bcnt--;
			}
			
		}
		if(acnt>n/2){
			sort(sco[0]+1,sco[0]+1+acnt,acmp);
			while(acnt>n/2){
				if(sco[0][acnt].b>sco[0][acnt].c)sco[1][++bcnt]=sco[0][acnt];
				if(sco[0][acnt].b<=sco[0][acnt].c)sco[2][++ccnt]=sco[0][acnt];
				acnt--;
			}
		}
		if(ccnt>n/2){
			sort(sco[2]+1,sco[2]+1+ccnt,ccmp);
			while(ccnt>n/2){
				if(sco[2][ccnt].a>sco[2][ccnt].b)sco[0][++acnt]=sco[2][ccnt];
				if(sco[2][ccnt].a<=sco[2][ccnt].b)sco[1][++bcnt]=sco[2][ccnt];
				ccnt--;
			}
		}	
		long long ans=0;
		for(int i=1;i<=acnt;i++){
			ans+=sco[0][i].a;
		}
		for(int i=1;i<=bcnt;i++){
			ans+=sco[1][i].b;
		}
		for(int i=1;i<=ccnt;i++){
			ans+=sco[2][i].c;
		}
		cout<<ans<<endl;
		acnt=0;
		bcnt=0;
		ccnt=0;
	}
}

