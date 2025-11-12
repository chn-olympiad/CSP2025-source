#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e5+5;
int T;
int n;
int a[MAXN][3];
int sp_A=0;
int tmp_list[MAXN];
bool cmp(int x,int y){return x>y;}
int ans=0,sum=0,cnt[3];
void dfs(int p){
	if (cnt[0]>n/2) return;
	if (cnt[1]>n/2) return;
	if (cnt[2]>n/2) return;
	if (p>n){
		ans=max(ans,sum);
		return;
	}
	for (int i=0;i<3;i++){
		cnt[i]++;
		sum+=a[p][i];
		dfs(p+1);
		cnt[i]--;
		sum-=a[p][i];
	}
}
struct node{
	int id,val;
};
node heap1[MAXN],heap2[MAXN],heap3[MAXN];
int siz1=0,siz2=0,siz3=0;
struct peo{
	int st,ed,rd;
	bool stf,edf,rdf;
}b[MAXN];
void push(node heap[],int &siz,node x){
	heap[++siz]=x;
	int now=siz;
	while (now>1){
		int pos=now>>1;
		if (heap[pos].val>heap[now].val) break;
		swap(heap[pos],heap[now]);
		now=pos;
	}
}
void pop(node heap[],int &siz){
	heap[1]=heap[siz--];
	int now=1;
	while (now<=siz/2){
		int pos=now<<1;
		if (heap[pos].val<heap[pos+1].val) pos++;
		if (heap[pos].val<heap[now].val) break;
		swap(heap[pos],heap[now]);
		now=pos;
	}
}
void f(int type,int id,int x){
	if (type==0) push(heap1,siz1,{id,x});
	else if (type==1) push(heap2,siz2,{id,x});
	else push(heap3,siz3,{id,x});
}
void check_push(int id){
	if (b[id].stf!=true){
		f(b[id].st,id,-a[id][b[id].st]+a[id][b[id].ed]);
		ans+=a[id][b[id].st];
		b[id].stf=true;
	}
	else if (b[id].edf!=true){
		f(b[id].ed,id,-a[id][b[id].ed]+a[id][b[id].ed]);
		ans+=a[id][b[id].ed];
		b[id].edf=true;
	}
	else{
		f(b[id].rd,id,-2e9);
		ans+=a[id][b[id].rd];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while (T--){
		siz1=siz2=siz3=0;
		ans=0;
		sp_A=0;
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if (a[i][1]==0) sp_A++;
			if (a[i][2]==0) sp_A++;
		}
		if (sp_A==2*n){
			for(int i=1;i<=n;i++) tmp_list[i]=a[i][0];
			sort(tmp_list+1,tmp_list+1+n,cmp);
			for (int i=1;i<=n/2;i++) ans+=tmp_list[i];
			cout<<ans<<endl;
		}
		else if (n<=10){
			ans=0,sum=0,cnt[0]=0,cnt[1]=0,cnt[2]=0;
			dfs(1);
			cout<<ans<<endl;
		}
		else{
			for (int i=1;i<=n;i++){
				b[i].st=0,b[i].ed=1,b[i].rd=2;
				b[i].stf=b[i].edf=b[i].rdf=false;
				if (a[i][b[i].st]<a[i][b[i].ed]) swap(b[i].st,b[i].ed);
				if (a[i][b[i].ed]<a[i][b[i].rd]) swap(b[i].ed,b[i].rd);
				if (a[i][b[i].st]<a[i][b[i].ed]) swap(b[i].st,b[i].ed);
//				cout<<b[i].st<<" "<<b[i].ed<<" "<<b[i].rd<<endl;
			}
			for (int i=1;i<=n;i++){
				check_push(i);
				if (siz1>n/2){
					int id=heap1[1].id;
					pop(heap1,siz1);
					if(b[id].edf==true) ans-=a[id][b[id].ed];
					else if (b[id].stf==true) ans-=a[id][b[id].st];
					check_push(id);
				}
				if (siz2>n/2){
					int id=heap2[1].id;
//					cout<<"remove:"<<id<<" val="<<heap2[1].val<<endl;
//					cout<<heap2[2].val<<" "<<heap2[3].val<<endl;
					pop(heap2,siz2);
					if(b[id].edf==true) ans-=a[id][b[id].ed];
					else if (b[id].stf==true) ans-=a[id][b[id].st];
//					cout<<id<<" "<<b[id].st<<endl;
//					cout<<"ans-="<<a[id][b[id].st]<<endl;
					check_push(id);
				}
				if (siz3>n/2){
					int id=heap3[1].id;
					pop(heap3,siz3);
					if(b[id].edf==true) ans-=a[id][b[id].ed];
					else if (b[id].stf==true) ans-=a[id][b[id].st];
					check_push(id);
				}
//				cout<<siz1<<" "<<siz2<<" "<<siz3<<" "<<ans<<endl;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
// rp++;

