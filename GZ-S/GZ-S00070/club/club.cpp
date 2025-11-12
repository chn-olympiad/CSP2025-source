//刘骏瑞 贵阳市清华中学  GZ-300070
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+20;
struct hg{
	int a,b,c,maxn;
	bool vis1,vis2,vis3;
}xs[N];
int xz[N];
bool cmp(hg a,hg b){
	if(a.maxn<b.maxn) return 1;
	else{
		return 0;
	}
}
bool cmp2(hg a,hg b){
	if(a.maxn>b.maxn) return 1;
	else{
		return 0;
	}
}
int lls[3];
void sd(int aa,int bb,int cc){
			if(aa>bb&&bb>cc){
				lls[0]=aa;
				lls[1]=bb;
				lls[2]=cc;
			}
			else if(aa>cc&&cc>bb){
				lls[0]=aa;
				lls[1]=cc;
				lls[2]=bb;
			}
			else if(bb>aa&&aa>cc){
				lls[0]=bb;
				lls[1]=aa;
				lls[2]=cc;
			}
			else if(bb>cc&&cc>aa){
				lls[0]=bb;
				lls[1]=cc;
				lls[2]=aa;
			}
			else if(cc>aa&&aa>bb){
				lls[0]=cc;
				lls[1]=aa;
				lls[2]=bb;
			}
			else if(cc>bb&&bb>aa){
				lls[0]=cc;
				lls[1]=bb;
				lls[2]=aa;
			}
			
			
			
			
			else if(aa==bb&&bb>cc){
				lls[0]=aa;
				lls[1]=bb;
				lls[2]=cc;
			}
			else if(aa==cc&&cc>bb){
				lls[0]=aa;
				lls[1]=cc;
				lls[2]=bb;
			}
			else if(bb==aa&&aa<cc){
				lls[0]=cc;
				lls[1]=aa;
				lls[2]=bb;
			}
			else if(bb==cc&&cc>aa){
				lls[0]=bb;
				lls[1]=cc;
				lls[2]=aa;
			}
			else if(cc==aa&&aa<bb){
				lls[0]=bb;
				lls[1]=aa;
				lls[2]=cc;
			}
			else if(cc==bb&&bb<aa){
				lls[0]=aa;
				lls[1]=bb;
				lls[2]=cc;
			}
			
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		int bz=n/2;
		int uu=0;
		for(int i=1;i<=n;i++){
			cin>>xs[i].a>>xs[i].b>>xs[i].c;
			if(xs[i].a<xs[i-1].a||xs[i].b<xs[i-1].b||xs[i].c<xs[i-1].c) uu=1;
			xs[i].maxn=xs[i].a+xs[i].b+xs[i].c;
		}
		if(uu==1)sort(xs+1,xs+1+n,cmp);
		else{
			sort(xs+1,xs+1+n,cmp2);
		}
		int b1=0,b2=0,b3=0;
		for(int i=1;i<=n;i++){
			sd(xs[i].a,xs[i].b,xs[i].c);
			for(int j=0;j<=2;j++){
				if(xs[i].a==lls[j]&&(b1+1<=bz)) {
					b1+=1;
					xs[i].vis1=1;
					xz[i]=lls[j];
					break;
				}
				else if(xs[i].b==lls[j]&&b2+1<=bz) {
					b2+=1;
					xs[i].vis2=1;
					xz[i]=lls[j];
					break;
				}
				else if(xs[i].c==lls[j]&&b3+1<=bz) {
					b3+=1;
					xs[i].vis3=1;
					xz[i]=lls[j];
					break;
				}
		}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=xz[i];
		}
		cout<<cnt<<'\n';
	}
	return 0;
}

