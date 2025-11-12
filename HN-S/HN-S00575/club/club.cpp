#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,lim;
struct Node{
	int a,b,c;
	int x,y,z,minn;
	int madex;
}er[N];
bool cmp(Node xx,Node yy){
	return xx.minn<=yy.minn;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		lim=n/2;
		int o1=0,o2=0,o3=0,ma=0;
		for(int i=1;i<=n;i++){
			cin>>er[i].a>>er[i].b>>er[i].c;
			int aa=er[i].a,bb=er[i].b,cc=er[i].c;
			if(aa>=bb){
				if(aa>=cc){
					er[i].x=er[i].a-er[i].b;
					er[i].y=er[i].a-er[i].c;
					er[i].madex=1;
					o1++;
					ma+=aa;
				}else{
					er[i].x=er[i].c-er[i].a;
					er[i].y=er[i].c-er[i].b;
					er[i].madex=3;
					o3++;
					ma+=cc;
				}
			}else{
				if(bb>=cc){
					er[i].x=er[i].b-er[i].a;
					er[i].y=er[i].b-er[i].c;
					er[i].madex=2;
					o2++;
					ma+=bb;
				}else{
					er[i].x=er[i].c-er[i].b;
					er[i].y=er[i].c-er[i].a;
					er[i].madex=3;
					o3++;
					ma+=cc;
				}
			}
			int xx=er[i].x,yy=er[i].y;
			er[i].minn=min(abs(xx),abs(yy));
		}
		sort(er+1,er+1+n,cmp);
		if(o1<=lim&&o2<=lim&&o3<=lim){
			cout<<ma<<'\n';
		}else{
			for(int i=1;i<=n;i++,o1>lim){
				if(er[i].madex==1){
					o1--;
					ma-=er[i].minn;
				}
			}for(int i=1;i<=n;i++,o2>lim){
				if(er[i].madex==2){
					o2--;
					ma-=er[i].minn;
				}
			}for(int i=1;i<=n;i++,o3>lim){
				if(er[i].madex==3){
					o3--;
					ma-=er[i].minn;
				}
			}
			cout<<ma<<'\n';
		}
	}
	return 0;
}

