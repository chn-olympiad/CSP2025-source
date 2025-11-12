#include<bits/stdc++.h>
using namespace std;
int t,n,ans,am,bm,cm,on,tw,th;
struct cnt {
	int one=0,two=0,three=0;
} a[100005],b[100005],c[100005];
bool cmp1(cnt a,cnt b) {
	return min(abs(a.one-a.two),abs(a.one-a.three))<min(abs(b.one-b.two),abs(b.one-b.three));
}
bool cmp2(cnt a,cnt b) {
	return min(abs(a.one-a.two),abs(a.two-a.three))<min(abs(b.one-b.two),abs(b.two-b.three));
}
bool cmp3(cnt a,cnt b) {
	return min(abs(a.two-a.three),abs(a.one-a.three))<min(abs(b.two-b.three),abs(b.one-b.three));
}
void aa(cnt a[],cnt b[],cnt c[]) {
	sort(a,a+am,cmp1);
	for(int i=0; on>n/2; i++) {
		on--;
		ans-=min(a[i].one-a[i].two,a[i].one-a[i].three);
		if(min(a[i].one-a[i].two,a[i].one-a[i].three)==a[i].one-a[i].two&&tw!=n/2)tw++,b[bm].one=a[i].one,b[bm].two=a[i].two,b[bm++].three=a[i].three;
		else th++,c[cm].one=a[i].one,c[cm].two=a[i].two,c[cm++].three=a[i].three;
	}
	return;
}
void bb(cnt a[],cnt b[],cnt c[]) {
	sort(b,b+bm,cmp2);
	for(int i=0; tw>n/2; i++) {
		tw--;
		ans-=min(b[i].two-b[i].one,b[i].two-b[i].three);
		if(min(b[i].two-b[i].one,b[i].two-b[i].three)==b[i].two-b[i].one&&on!=n/2)on++,a[am].one=b[i].one,a[am].two=b[i].two,a[am++].three=b[i].three;
		else th++,c[cm].one=b[i].one,c[cm].two=b[i].two,c[cm++].three=b[i].three;
	}
	return;
}
void cc(cnt a[],cnt b[],cnt c[]) {
	sort(c,c+cm,cmp3);
	for(int i=0; th>n/2; i++) {
		th--;
		ans-=min(c[i].three-c[i].two,c[i].three-c[i].one);
		if(min(c[i].three-c[i].two,c[i].three-c[i].one)==c[i].three-c[i].two&&tw!=n/2)tw++,b[bm].one=c[i].one,b[bm].two=c[i].two,b[bm++].three=c[i].three;
		else th++,a[am].one=c[i].one,a[am].two=c[i].two,a[am++].three=c[i].three;
	}
	return;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		ans=0;
		on=0,tw=0,th=0;
		am=0,bm=0,cm=0;
		cin>>n;
		memset(a,(0,0,0),sizeof a);
		memset(b,(0,0,0),sizeof b);
		memset(c,(0,0,0),sizeof c);
		for(int i=0; i<n; i++) {
			int ab,ac,bc;
			cin>>ab>>ac>>bc;
			if(ab>ac&&ab>bc)on++,ans+=ab,a[am].one=ab,a[am].two=ac,a[am++].three=bc;
			else if(ac>ab&&ac>bc)tw++,ans+=ac,b[bm].one=ab,b[bm].two=ac,b[bm++].three=bc;
			else if(bc>ab&&bc>ac)th++,ans+=bc,c[cm].one=ab,c[cm].two=ac,c[cm++].three=bc;
		}
		if(on>n/2) {
			aa(a,b,c);
			if(tw>n/2)bb(a,b,c);
			if(th>n/2)cc(a,b,c);
		} else if(tw>n/2) {
			bb(a,b,c);
			if(on>n/2)aa(a,b,c);
			if(th>n/2)cc(a,b,c);
		} else if(th>n/2) {
			cc(a,b,c);
			if(tw>n/2)bb(a,b,c);
			if(on>n/2)aa(a,b,c);
		}
		cout<<ans<<endl;
	}
	return 0;
}
