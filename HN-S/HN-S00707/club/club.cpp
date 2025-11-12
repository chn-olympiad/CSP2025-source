#include<bits/stdc++.h>
using namespace std;
const int N=1E5+5;
bool pd1=1,pd2=1;
struct st{
	int a,b,c;
}a[N];
bool cmp(st x,st y){
	return x.a>y.a;
}
int n;
int f(int x,int s1,int s2,int s3,int cnt1,int cnt2,int cnt3){
	if(cnt1+cnt2+cnt3==n) return s1+s2+s3;
	if(cnt1==n/2) return max(f(x+1,s1,s2+a[x].b,s3,cnt1,cnt2+1,cnt3),f(x+1,s1,s2,s3+a[x].c,cnt1,cnt2,cnt3+1));
	else if(cnt2==n/2) return max(f(x+1,s1+a[x].a,s2,s3,cnt1+1,cnt2,cnt3),f(x+1,s1,s2,s3+a[x].c,cnt1,cnt2,cnt3+1));
	else if(cnt3==n/2) return max(f(x+1,s1+a[x].a,s2,s3,cnt1+1,cnt2,cnt3),f(x+1,s1,s2+a[x].b,s3,cnt1,cnt2+1,cnt3));
	else return max(max(f(x+1,s1+a[x].a,s2,s3,cnt1+1,cnt2,cnt3),f(x+1,s1,s2+a[x].b,s3,cnt1,cnt2+1,cnt3)),f(x+1,s1,s2,s3+a[x].c,cnt1,cnt2,cnt3+1));
}
int f1(int x,int s1,int s2,int cnt1,int cnt2){
	if(cnt1+cnt2==n) return s1+s2;
	if(cnt1==n/2) return f1(x+1,s1,s2+a[x].b,cnt1,cnt2+1);
	else if(cnt2==n/2) return f1(x+1,s1+a[x].a,s2,cnt1+1,cnt2);
	else return max(f1(x+1,s1+a[x].a,s2,cnt1+1,cnt2),f1(x+1,s1,s2+a[x].b,cnt1,cnt2+1));
}
int lcx(){
	if(pd1){
		int s1=0;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++) s1+=a[i].a;
		cout<<s1;
	}else if(pd2) cout<<f1(1,0,0,0,0)<<endl;
	else cout<<f(1,0,0,0,0,0,0)<<endl;
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b!=0) pd1=pd2=0;
			if(a[i].c!=0) pd2=0;
		}
		lcx();
	}
	return 0;
} 
