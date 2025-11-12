#include<iostream>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
struct cy{
	int a,b,c;
}m[100000];
int ans=0;
bool cmp(cy d,cy e){
	return max(d.a,max(d.b,d.c))>max(e.a,max(e.b,e.c));
}
signed main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int ppp=0;ppp<t;ppp++){
		int n,ac,bc,cc;
		cin>>n;
		ac=bc=cc=n/2;
		for(int i=0;i<n;i++)cin>>m[i].a>>m[i].b>>m[i].c;
		sort(m,m+n,cmp);
		int i=0;
		while((ac||bc||cc)&&i<n){
			if(m[i].a>m[i].b){
				if(m[i].a>m[i].c&&ac){
					ans+=m[i].a,ac--;
				}else{
					if(m[i].a==m[i].c){
						if(ac>cc&&ac)ans+=m[i].a,ac--;
						else if(cc)ans+=m[i].c,cc--;
					}else if(cc){
						ans+=m[i].c,cc--;
					}
				}
			}else{
				 if(m[i].b>m[i].c&&bc){
				 	ans+=m[i].b,bc--;
				 }else{
				 	if(m[i].b==m[i].c){
				 		if(bc>cc&&bc)ans+=m[i].b,bc--;
						else if(cc)ans+=m[i].c,cc--;
					 }else if(cc){
					 	ans+=m[i].c,cc--;
					 }
				 }
			}
			i++;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
