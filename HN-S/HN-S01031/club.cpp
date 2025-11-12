#include<bits/stdc++.h>
using namespace std;
template<typename type>
inline void read(type &x){
	x=0;bool flag(0);char ch=getchar();
	while(!isdigit(ch)) flag=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	flag?x=-x:0;
}
const int N=1e5+10;
struct node{
	int a,b,c;
	int id;
	//a: 1
	//b: 2
	//c: 3
}e[N];
int n,a[N][4],b[4],bel[N],sum;
bool cmp1(node a,node b){return a.a<b.a;}
bool cmp2(node a,node b){return a.b<b.b;}
bool cmp3(node a,node b){return a.c<b.c;}
inline void work(int i){
	int cnt=b[i]-n/2;
	if(i==1){
		sort(e+1,e+n+1,cmp1);
//		for(int i=1;i<=b[i];i++) cout<<e[i].a<<" ";
//		puts("");
//		cout<<sum<<endl;
		for(int j=1;j<=n&&cnt;j++){
//			puts("c");
			if(bel[e[j].id]==1) sum-=e[j].a,cnt--;
		}
		return;
	}
	if(i==2){
		sort(e+1,e+n+1,cmp2);
		for(int j=1;j<=n&&cnt;j++){
			if(bel[e[j].id]==2) sum-=e[j].b,cnt--;
		}
		return;
	}
	if(i==3){
		sort(e+1,e+n+1,cmp3);
		for(int j=1;j<=n&&cnt;j++){
			if(bel[e[j].id]==3) sum-=e[j].c,cnt--;
		}
		return;
	}
}
inline void solve(){
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i][1]),read(a[i][2]),read(a[i][3]);
		e[i].a=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
		e[i].b=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
		e[i].c=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
		e[i].id=i;
	}//≤Ó 
	for(int i=1;i<=n;i++){
		if(a[i][1]>a[i][2]){
			if(a[i][1]>a[i][3]){
				b[1]++;
				bel[i]=1;
				sum+=a[i][1];
			}else{
				b[3]++;
				bel[i]=3;
				sum+=a[i][3];
			}
		}else{
			if(a[i][2]>a[i][3]){
				b[2]++;
				bel[i]=2;
				sum+=a[i][2];
			}else{
				b[3]++;
				bel[i]=3;
				sum+=a[i][3];
			}
		}
	} //∑÷ 
	for(int i=1;i<=3;i++){
		if(b[i]>n/2){
			work(i);
			break;
		}
	} //‘» 
	printf("%d\n",sum);
	for(int i=1;i<=n;i++){
		bel[i]=0;
		for(int j=1;j<=3;j++){
			a[i][j]=0;
		}
	} 
	b[1]=b[2]=b[3]=sum=0;
	  //πÈ 
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	read(T);
	while(T--){
		solve();
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
