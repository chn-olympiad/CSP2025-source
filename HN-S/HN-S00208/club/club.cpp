#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e5+10;
int t,n;
struct node{
	int val,idx;
}; 
node l[N],r[N],c[N];
int a[N][4],len=0,ren=0,cen=0;
bool cmp(node x,node y){
	return x.val>y.val;
}
void init(){
	for(int i=1;i<=N-20;++i)l[i].val=0,l[i].idx=0;
	for(int i=1;i<=N-20;++i)r[i].val=0,r[i].idx=0;
	for(int i=1;i<=N-20;++i)c[i].val=0,c[i].idx=0;
	len=0,ren=0,cen=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i){
			int maxn=-1e9,id;
			for(int j=1;j<=3;++j){
				cin>>a[i][j];
				if(maxn<a[i][j]){
					maxn=a[i][j],id=j;
				}
			}
			if(id==1)l[++len].idx=i,l[len].val=maxn;
			else if(id==2)r[++ren].idx=i,r[ren].val=maxn;
			else if(id==3)c[++cen].idx=i,c[cen].val=maxn;
		}
		sort(l+1,l+1+len,cmp);
		sort(r+1,r+1+ren,cmp);
		sort(c+1,c+1+cen,cmp);
		int lenmax=n/2;
		bool flag1=false,flag2=false;
		if(len>lenmax){
			for(int i=len;i>=lenmax+1;--i){
				int idxx=l[i].idx,maxx;
				bool f;
				if(a[idxx][2]>a[idxx][3])maxx=a[idxx][2],f=true;
				else maxx=a[idxx][3],f=false;
				len--;
				if(f==true){
					if(ren<lenmax){
						r[++ren].val=a[idxx][2];
						flag1=true;
					}
					else{
						c[++cen].val=a[idxx][3];
						flag2=true;
					}
				}
				else{
					if(cen<lenmax){
						c[++cen].val=a[idxx][3];
						flag2=true;
					}
					else{
						r[++ren].val=a[idxx][2];
						flag1=true;
					}
				}
			}
		}
		if(flag1==true){
			sort(r+1,r+1+ren,cmp);
		}
		if(ren>lenmax){
			for(int i=ren;i>=lenmax+1;--i){
				int idxx=r[i].idx,maxx;
				bool f;
				if(a[idxx][1]>a[idxx][3]){
					maxx=a[idxx][1];
					f=true;
				}
				else{
					maxx=a[idxx][3];
					f=false;
				}
				ren--;
				if(f==true){
					if(len<lenmax)l[++len].val=a[idxx][1];
					else{
						c[++cen].val=a[idxx][3];
						flag2=true;
					}
				}
				else{
					if(cen<lenmax){
						c[++cen].val=a[idxx][3];
						flag2=true;
					}
					else l[++len].val=a[idxx][1];
				}
			}
		}
		if(flag2==true){
			sort(c+1,c+1+cen,cmp);
		}
		if(cen>lenmax){
			for(int i=cen;i>=lenmax+1;--i){
				int idxx=c[i].idx,maxx;
				bool f;
				if(a[idxx][1]>a[idxx][2]){
					maxx=a[idxx][1];
					f=true;
				}
				else{
					maxx=a[idxx][2];
					f=false;
				}
				cen--;
				if(f==true){
					if(len<lenmax)l[++len].val=a[idxx][1];
					else r[++ren].val=a[idxx][2];
				}
				else{
					if(ren<lenmax)r[++ren].val=a[idxx][2];
					else l[++len].val=a[idxx][1];
				}
			}
		}
		ll sum=0;
		for(int i=1;i<=len;++i){
			sum+=l[i].val;
		}
		for(int i=1;i<=ren;++i){
			sum+=r[i].val;
		}
		for(int i=1;i<=cen;++i){
			sum+=c[i].val; 
		}
		cout<<sum<<"\n";
		init();
	}
	return 0;
} 
