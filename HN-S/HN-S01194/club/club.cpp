#include<bits/stdc++.h>
using namespace std;
struct node{
	int maxn,cmaxn,f,cf;
}r[100005];
bool cmp(node a,node b){
	return a.maxn>b.maxn;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,cuta=0,cutb=0,cutc=0,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			if(a>=b){
				if(a>=c){
					r[i].maxn=a;
					r[i].f=1;
					if(b>=c){
						r[i].cf=2;
						r[i].cmaxn=b;
					}
					else{
						r[i].cf=3;
						r[i].cmaxn=c;
					}
				}
				else{
					r[i].f=3;
					r[i].maxn=c;
					r[i].cf=1;
					r[i].cmaxn=a;
				}
			}
			else if(b>=c){
				r[i].f=2;
				r[i].maxn=b;
				if(a>=c){
					r[i].cf=1;
					r[i].cmaxn=a;
				}
				else{
					r[i].cf=3;
					r[i].cmaxn=c;
				}
			}
			else{
				r[i].f=3;
				r[i].maxn=c;
				r[i].cf=2;
				r[i].cmaxn=b;
			}
			r[i].maxn-=r[i].cmaxn;
		}
		sort(r+1,r+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(r[i].f==1){
				if(cuta==n/2){
					sum+=r[i].cmaxn;
				}
				else{
					cuta++;
					sum+=r[i].maxn+r[i].cmaxn;
				}
			}
			else if(r[i].f==2){
				if(cutb==n/2){
					sum+=r[i].cmaxn;
				}
				else{
					cutb++;
					sum+=r[i].maxn+r[i].cmaxn;
				}
			}
			else if(r[i].f==3){
				if(cutc==n/2){
					sum+=r[i].cmaxn;
				}
				else{
					cutc++;
					sum+=r[i].maxn+r[i].cmaxn;
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			cout<<r[i].maxn<<" "<<r[i].f<<" "<<r[i].cmaxn<<" "<<r[i].cf<<"\n";
//		}
//		cout<<cuta<<" "<<cutb<<" "<<cutc<<"\n";
		cout<<sum<<"\n";
	}
	return 0;
}

