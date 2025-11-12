#include<bits/stdc++.h>
using namespace std;
int t,n;
const int N = 1e5+10;
int aa = 1,bb = 1,cc = 1,ai = 1,bi = 1,ci = 1;
struct node{
	int a,b,c,id;
}a1[N],b1[N],c1[N];

bool cmpa(node t1,node t2){
	return t1.a>t2.a;
}

bool cmpb(node t1,node t2){
	return t1.b>t2.b;
}

bool cmpc(node t1,node t2){
	return t1.c>t2.c;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==2){
			long long suma = 0,sumb = 0,sumc = 0;
			int ax1,bx1,cx1,ax2,bx2,cx2,aaa = 1,bbb = 1;
			cin>>ax1>>bx1>>cx1>>ax2>>bx2>>cx2;
			if(ax1>=bx1&&ax1>=cx1){
				if(ax1>ax2&&aaa){
					suma+=ax1;
					aaa = 0;
				}
				else{
					if(ax2>=bx2&&ax2>=cx2&&bbb){
						suma+=ax2;
						bbb = 0;
					}
					else if(aaa){
						suma+=ax1;
						aaa = 0;
					}
				}
			}
			else if(bx1>=ax1&&bx1>=cx1){
				if(bx1>bx2&&aaa){
					sumb+=bx1;
					aaa = 0;
				}
				else{
					if(bx2>=ax2&&bx2>=cx2&&bbb){
						sumb+=bx2;
						bbb = 0;
					}
					else if(aaa){
						sumb+=bx1;
						aaa = 0;
					}
				}
			}
			else if(cx1>=ax1&&cx1>=cx1){
				if(cx1>cx2&&aaa){
					sumc+=cx1;
					aaa = 0;
				}
				else{
					if(cx2>=ax2&&cx2>=bx2&&bbb){
						sumc+=cx2;
						bbb = 0;
					}
					else if(aaa){
						sumc+=cx1;
						aaa = 0;
					}
				}
			}
			cout<<max(max(suma,sumb),sumc)<<endl;
		}
		ai = 1,bi = 1,ci = 1;
		for(int i = 1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			if(b!=0||c!=0){
				aa = 0;
			}
			if(c!=0){
				bb = 0;
			}
			if(a>=b&&a>=c){
				a1[ai].a = a;
				a1[ai].b = b;
				a1[ai].c = c;
				ai++;
			}
			else if(b>=a&&b>=c){
				b1[bi].a = a;
				b1[bi].b = b;
				b1[bi].c = c;
				bi++;
			}
			else{
				c1[ci].a = a;
				c1[ci].b = b;
				c1[ci].c = c;
				ci++;
			}
		}
		sort(a1+1,a1+ai+1,cmpa);
		sort(b1+1,b1+bi+1,cmpb);
		sort(c1+1,c1+ci+1,cmpc);
		if(aa){
			long long suma = 0;
			for(int i = 1;i<=n/2;i++){
				suma +=a1[i].a;
			}
			cout<<suma<<endl;
		}
		else if(bb){
			long long suma = 0,sumb = 0;
			if(ai>=bi){
				for(int i = 1;i<=ai;i++){
					if(i>n/2){
						sumb+=a1[i].b;
					}
					else{
						suma+=a1[i].a;
					}
				}
				for(int i = 1;i<=bi;i++){
					sumb+=b1[i].b;
				}
			}
			else{
				for(int i = 1;i<=bi;i++){
					if(i>n/2){
						suma+=b1[i].a;
					}
					else{
						sumb+=b1[i].b;
					}
				}
				for(int i = 1;i<=ai;i++){
					suma+=a1[i].a;
				}
			}
			cout<<max(suma,sumb)<<endl;
		}
	}
	return 0;
}
