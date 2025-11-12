#include<bits/stdc++.h>
using namespace std;
int n,ans;
struct kkk{
	int a,b,c;
}s[100005];
void bl(int x,int summ,int aa,int bb,int cc){
	if(x==n+1){
		ans=max(ans,summ);
		return;
	}
	if(aa<n/2){
		bl(x+1,summ+s[x].a,aa+1,bb,cc);
	}
	if(bb<n/2){
		bl(x+1,summ+s[x].b,aa,bb+1,cc);
	}
	if(cc<n/2){
		bl(x+1,summ+s[x].c,aa,bb,cc+1);
	}
}
bool cmp(kkk x,kkk y){
	return x.a>y.a;
	} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		ans=0;
		int f3=0,f2=0;
		for(int j=1;j<=n;j++){
			cin>>s[j].a>>s[j].b>>s[j].c;
			if(s[j].b!=0)
			f2=1;
			if(s[j].c!=0)
			f3=1;
		}
		 if(f2==0&&f3==0){
			sort(s+1,s+n+1,cmp);
			for(int j=1;j<=n/2;j++){
				ans+=s[j].a;
			}
			cout<<ans<<endl;
			continue;
		}
		bl(0,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
