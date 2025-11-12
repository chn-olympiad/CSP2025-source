#include<bits/stdc++.h>
using namespace std;
int t,n;
long long answer[10];
struct lll{
	int a,b,c;
}peo[1000100];
bool b_=1,c_=1;
cmp(lll x,lll y){
	return max(max(x.a,x.b),x.c)-min(min(x.a,x.b),x.c)>max(max(y.a,y.b),y.c)-min(min(y.a,y.b),y.c);
}
cmp_(lll x,lll y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int h=0;h<t;h++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>peo[i].a>>peo[i].b>>peo[i].c;
			if(peo[i].b!=0){
				b_=0;
			}
			if(peo[i].c!=0){
				c_=0;
			}
		}
		if(b_&&c_){
			sort(peo,peo+n,cmp_);
		}else{
			sort(peo,peo+n,cmp);
		}
		int cna=0,cnb=0,cnc=0;
		for(int i=0;i<n;i++){
			if(peo[i].a>=peo[i].b&&cna<n/2){
				if(peo[i].a>=peo[i].c){
					cna++;
					answer[h]+=peo[i].a;
					continue;
				}
			}
			if(peo[i].b>=peo[i].a&&cnb<n/2){
				if(peo[i].b>=peo[i].c){
					cnb++;
					answer[h]+=peo[i].b;
					continue;
				}
			}
			if(peo[i].c>=peo[i].b&&cnc<n/2){
					if(peo[i].c>=peo[i].a){
						cnc++;
						answer[h]+=peo[i].c;
						continue;
					}
				}
			if(peo[i].a>=peo[i].b&&cna==n/2){
				if(peo[i].b>=peo[i].c&&cnb<n/2){
					
					cnb++;
					answer[h]+=peo[i].b;
					continue;
				}else if(cnc<n/2){
					cnc++;
					answer[h]+=peo[i].c;
					continue;
				}else if(cnc==n/2){
					cnb++;
					answer[h]+=peo[i].b;
					continue;
				}
			}
			if(peo[i].b>=peo[i].a&&cnb==n){
				if(peo[i].a>=peo[i].c&&cna<n/2){
					cna++;
					answer[h]+=peo[i].a;
					continue;
				}else if(cna==n/2){
					cnc++;
					answer[h]+=peo[i].c;
					continue;
				}
			}
			if(peo[i].c>peo[i].b&&cnc==n){
				if(peo[i].b>=peo[i].a&&cnb<n/2){
					cnb++;
					answer[h]+=peo[i].b;
					continue;
				}else if(cnb==n/2){
					cna++;
					answer[h]+=peo[i].a;
					continue;
				}
			}
		}
	}
	for(int i=0;i<t;i++){
		cout<<answer[i]<<endl;
	}
	return 0;
}
