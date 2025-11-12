#include<bits/stdc++.h>
using namespace std;
struct node{
	int ft,sc,kl,a1,b1;
}e[100010];
int T,n,t;
bool cmp(node n1,node n2){
	return n1.kl>n2.kl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		t=0;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			e[i].ft=max(a,max(b,c));
			if(e[i].ft==a){
				e[i].a1=1;
				if(b>c){
					e[i].sc=b;
					e[i].b1=2;
				}else{
					e[i].sc=c;
					e[i].b1=3;
				}
			}else if(e[i].ft==b){
				e[i].a1=2;
				if(a>c){
					e[i].sc=a;
					e[i].b1=1;
				}else{
					e[i].sc=c;
					e[i].b1=3;
				}
			}else if(e[i].ft==c){
				e[i].a1=3;
				if(b>a){
					e[i].sc=b;
					e[i].b1=2;
				}else{
					e[i].sc=a;
					e[i].b1=1;
				}
			}
			e[i].kl=e[i].ft-e[i].sc;
		}
		int a[5];
		a[1]=a[2]=a[3]=n/2;
		sort(e+1,e+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(a[e[i].a1]==0){
				a[e[i].b1]--;
				t+=e[i].sc;
			}else{
				a[e[i].a1]--;
				t+=e[i].ft;
			}
		}
		cout<<t<<endl;
	}
	return 0;
}
