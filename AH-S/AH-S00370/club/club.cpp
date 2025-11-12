#include<bits/stdc++.h>
using namespace std;
int t,n;
struct num{
	int a,b,c,s1,s2;
}st[100005];
bool cmp(const num x,const num y){
	return x.s2<y.s2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int n1=0,n2=0,n3=0,sf=0;
		for(int i=1;i<=n;i++){
			cin>>st[i].a>>st[i].b>>st[i].c;
			int maxn=max(st[i].a,max(st[i].b,st[i].c));
			if(st[i].a==maxn){
				st[i].s1=1; n1++;
				sf+=st[i].a; 
				st[i].s2=st[i].a-max(st[i].b,st[i].c);
			}
			else if(st[i].b==maxn){
				st[i].s1=2; n2++;
				sf+=st[i].b; 
				st[i].s2=st[i].b-max(st[i].a,st[i].c);
			}
			else{
				st[i].s1=3; n3++;
				sf+=st[i].c; 
				st[i].s2=st[i].c-max(st[i].a,st[i].b);
			}
		}
		sort(st+1,st+n+1,cmp);
		n/=2;
		if(n1>=n){
			int tot=0;
			while(n1>n){
				if(st[++tot].s1==1){
					sf-=st[tot].s2;
					n1--;
				}
			}
		}
		else if(n2>=n){
			int tot=0;
			while(n2>n){
				if(st[++tot].s1==2){
					sf-=st[tot].s2;
					n2--;
				}
			}
		}
		else if(n3>=n){
			int tot=0;
			while(n3>n){
				if(st[++tot].s1==3){
					sf-=st[tot].s2;
					n3--;
				}
			}
		}
		cout<<sf<<endl;
	}
	return 0;
}
