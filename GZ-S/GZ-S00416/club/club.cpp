//GZ-S00416 谭怡鹏 恒升高级中学
#include<bits/stdc++.h>
using namespace std;
int s,n,t;
struct sb{
	int a;
	int b;
	int c;
};
sb a[100010];
bool tmp(sb a,sb b){
	if(a.a!=b.a)return a.a>b.a;
}
void bs(int l,int f,int aa,int bb,int cc){
	if(l==n-1){
		s=max(s,f);
		return;
	}
	int x=l+1;
	if(aa<n/2)bs(x,f+a[x].a,aa+1,bb,cc);
	if(bb<n/2)bs(x,f+a[x].b,aa,bb+1,cc);
	if(cc<n/2)bs(x,f+a[x].c,aa,bb,cc+1);
}
void bbs(int l,int f,int aa,int bb){
	if(l==n-1){
		s=max(s,f);
		return;
	}
	int x=l+1;
	if(aa<n/2)bbs(x,f+a[x].a,aa+1,bb);
	if(bb<n/2)bbs(x,f+a[x].b,aa,bb+1);

}
int main(){
	freopen("clud.in","r",stdin);
	freopen("clud.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int cc=0,bb=0,aa=0;
		for(int x=0;x<n;x++){
			cin>>a[x].a>>a[x].b>>a[x].c;
			if(a[x].b==0)bb++;
			if(a[x].c==0)cc++;
			if(a[x].a==0)aa++;
		}
		if(cc==n && bb==n){
			sort(a,a+n,tmp);
			int s=0;
			for(int x=0;x<=n/2;x++)s+=a[x].a;
			cout<<s<<endl;
		}
		else if(cc==n && bb!=n){
			s=0;
			bbs(-1,0,0,0);
			cout<<s<<endl;
		}
		else{
			s=0;
			bs(-1,0,0,0,0);
			cout<<s<<endl;
		}
	}

	return 0;
}
