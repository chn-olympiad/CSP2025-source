#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t;
int n;
struct student{
	int a,b,c;
}s[100010];
int ans=0;
int s1,s2,s3;
int ta[100010],tb[100010],tc[100010];
int k[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(register int i=1;i<=t;i++){
	    cin>>n;
		for(register int j=1;j<=n;++j){
			cin>>s[j].a>>s[j].b>>s[j].c;
			int ma=max(max(s[j].a,s[j].b),s[j].c);
			if(s[j].a==ma){
				ta[++s1]=j;
			}else if(s[j].b==ma){
				tb[++s2]=j;
			}else if(s[j].c==ma){
				tc[++s3]=j;
			}
			ans+=ma;
		}
		if(s1>n/2){
			for(register int j=1;j<=s1;++j){
				k[j]=min(s[ta[j]].a-s[ta[j]].b,s[ta[j]].a-s[ta[j]].c);
			}
			sort(k+1,k+s1+1);
			for(register int j=1;j<=s1-n/2;j++){
				ans-=k[j];
			}
		}else if(s2>n/2){
			for(register int j=1;j<=s2;++j){
				k[j]=min(s[tb[j]].b-s[tb[j]].a,s[tb[j]].b-s[tb[j]].c);
			}
			sort(k+1,k+s2+1);
			for(register int j=1;j<=s2-n/2;j++){
				ans-=k[j];
			}
		}else if(s3>n/2){
			for(register int j=1;j<=s3;++j){
				k[j]=min(s[tc[j]].c-s[tc[j]].b,s[tc[j]].c-s[tc[j]].a);	
			}
			sort(k+1,k+s3+1);
			for(register int j=1;j<=s3-n/2;j++){
				ans-=k[j];
			}
		}
		s1=0;s2=0;s3=0;
		cout<<ans<<endl;
		ans=0;						
	}
	return 0;
}
