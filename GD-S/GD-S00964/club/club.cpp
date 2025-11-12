#include<bits/stdc++.h>
using namespace std;
long long f[100100];
struct note{
	long long one,two,three;
}a[100100],c1[100100],c2[100100],c3[100100];
bool cmp1(note x,note y){
	if(x.one==y.one&&x.two==y.two) return (x.one-x.three)<(y.one-y.three);
	return (x.one-x.two)<(y.one-y.two);
}
bool cmp2(note x,note y){
	return (x.two-x.three)<(y.two-y.three);
}
bool cmp11(note x,note y){
	return x.one>y.one;
}
bool cmp22(note x,note y){
	return x.two>y.two;
}
bool cmp33(note x,note y){
	return x.three>y.three;
}
void solve(){
	memset(a,sizeof a,0);
	for(long long i=0;i<=100000;i++){
		f[i]=0;
		c1[i].one=c1[i].three=c1[i].two=0;
		c2[i].one=c2[i].three=c2[i].two=0;
		c3[i].one=c3[i].three=c3[i].two=0;
	}
	long long n;
	cin>>n;
	long long nn=n/2;
	long long ttt=1,tt=1;
	for(long long i=1;i<=n;i++){
		cin>>a[i].one>>a[i].two>>a[i].three; 
		if(a[i].two!=0&&a[i].three!=0) ttt=0;
		if(a[i].three!=0) tt=0;
	}
	if(ttt==1){
		long long sss=0;
		sort(a+1,a+n+1,cmp11);
		for(long long i=1;i<=nn;i++){
			sss+=a[i].one;
		}
		cout<<sss;
	}
	
	long long j1=1,j2=1,j3=1;
	for(int i=1;i<=n;i++){
		long long maxx=max(max(a[i].one,a[i].two),a[i].three);
		if(maxx==a[i].one){
			c1[j1].one=a[i].one;
			c1[j1].two=a[i].two;
			c1[j1].three=a[i].three;
			j1++;
		}
		else if(maxx==a[i].two){
			c2[j2].one=a[i].one;
			c2[j2].two=a[i].two;
			c2[j2].three=a[i].three;
			j2++;
		}
		else if(maxx==a[i].three){
			c3[j3].one=a[i].one;
			c3[j3].two=a[i].two;
			c3[j3].three=a[i].three;
			j3++;
		}
	}
	
	sort(c1+1,c1+j1,cmp11);
	if(j1>nn){
		for(long long i=j1;i>nn;i--){
			if(a[i].two>=a[i].three){
				c2[j2].one=c1[i].one;
				c2[j2].two=c1[i].two;
				c2[j2].three=c1[i].three;
				c1[j1].one=c1[j1].two=c1[j1].three=0;
				j2++;
				j1--;
			}
			else{
				c3[j3].one=c1[i].one;
				c3[j3].two=c1[i].two;
				c3[j3].three=c1[i].three;
				c1[j1].one=c1[j1].two=c1[j1].three=0;
				j3++;
				j1--;
			}
		}
	}
	sort(c2+1,c2+j2,cmp22);
	if(j2>nn){
		for(long long i=j2;i>nn;i--){
			c3[j3].one=c2[i].one;
			c3[j3].two=c2[i].two;
			c3[j3].three=c2[i].three;
			c2[j2].one=c2[j2].two=c2[j2].three=0;
			j3++;
			j2--;
		}
	}
	long long ans=0;
	sort(c1+1,c1+j1,cmp11);
	sort(c2+1,c2+j2,cmp22);
	sort(c3+1,c3+j3,cmp33);
	for(int i=1;i<=nn;i++) ans+=c1[i].one;
	for(int i=1;i<=nn;i++) ans+=c2[i].two;
	for(int i=1;i<=j3;i++) ans+=c3[i].three;
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr); 
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	
	return 0;
}
