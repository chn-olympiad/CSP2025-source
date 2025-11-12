#include<bits/stdc++.h>
using namespace std;
long long t,n,cnt1=0,cnt2=0,cnt3=0,cnt=0;
struct ss{
	long long s1,s2,s3,p,c;
}s[100005];
struct aa{
	long long name,sm;
}a[100005];
bool cmp(aa a,aa b){
	return a.sm<=b.sm;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cnt=0;
		cnt1=0;
		cnt2=0;
		cnt3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].s1>>s[i].s2>>s[i].s3;
			if(s[i].s1>=s[i].s2&&s[i].s1>=s[i].s3){
				s[i].p=1;
				cnt1++;
				s[i].c=s[i].s1;
			}else if(s[i].s2>s[i].s1&&s[i].s2>s[i].s3){
				s[i].p=2;
				cnt2++;
				s[i].c=s[i].s2;
			}else {
				s[i].p=3;
				cnt3++;
				s[i].c=s[i].s3;
			}
			cnt+=s[i].c;
		}
		if(cnt1>n/2){
			for(int i=1;i<=n;i++){
				a[i].sm=100000000000;
				a[i].name=i;
				if(s[i].p==1){
					a[i].sm=min(s[i].c-s[i].s2,s[i].c-s[i].s3);
				}
			}
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=cnt1-n/2;i++){
				cnt-=a[i].sm;
			}
		}else if(cnt2>n/2){
			for(int i=1;i<=n;i++){
				a[i].sm=100000000000;
				a[i].name=i;
				if(s[i].p==2){
					a[i].sm=min(s[i].c-s[i].s1,s[i].c-s[i].s3);
				}
			}
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=cnt2-n/2;i++){
				cnt-=a[i].sm;
			}
		}else if(cnt3>n/2){
			for(int i=1;i<=n;i++){
				a[i].sm=100000000000;
				a[i].name=i;
				if(s[i].p==3){
					a[i].sm=min(s[i].c-s[i].s2,s[i].c-s[i].s1);
				}
			}
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=cnt3-n/2;i++){
				cnt-=a[i].sm;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
