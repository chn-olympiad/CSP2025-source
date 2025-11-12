#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;

struct node{
	int a,b,c,mx;
}ar[N];
int n,t;
ll ans;
int que[N];
inline int read(){
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int sum=0;
	while(isdigit(ch)){sum=sum*10+ch-'0'; ch=getchar();}
	return sum;
}
void merge(int l,int r){
	if(l>=r) return;
	int bas,tmp,orl=l,orr=r;
	bas=que[l];
	l++;
	tmp=que[l];
	while(l<r){
		if(ar[bas].mx>ar[tmp].mx){
			que[r]=tmp;
			tmp=que[--r];
		}
		else{
			que[l]=tmp;
			tmp=que[++l];
		}
	}
	que[l]=bas;
	merge(orl,r-1);
	merge(l+1,orr);
	return;
}
int pa,pb,pc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		for(int i=1 ; i<=n ; i++){
			ar[i].a=read();
			ar[i].b=read();
			ar[i].c=read();
			ar[i].mx=max(ar[i].a,max(ar[i].b,ar[i].c));
			que[i]=i;
		}
		merge(1,n);
		for(int i=1 ; i<=n ; i++){
			if(ar[que[i]].mx==ar[que[i]].a){
				ans+=ar[que[i]].mx;
				pa++;
				if(pa>=n/2){
					for(int j=i ; j<=n ; j++){
						ar[que[j]].mx=max(ar[que[j]].b,ar[que[j]].c);
					}
					merge(i+1,n);
				}
			}
			else if(ar[que[i]].mx==ar[que[i]].b){
				ans+=ar[que[i]].mx;
				pb++;
				if(pb>=n/2){
					for(int j=i ; j<=n ; j++){
						ar[que[j]].mx=max(ar[que[j]].a,ar[que[j]].c);
					}
					merge(i+1,n);
				}
			}
			else if(ar[que[i]].mx==ar[que[i]].c){
				ans+=ar[que[i]].mx;
				pc++;
				if(pc>=n/2){
					for(int j=i ; j<=n ; j++){
						ar[que[j]].mx=max(ar[que[j]].b,ar[que[j]].a);
					}
					merge(i+1,n);
				}
			}
		}
		printf("%lld\n",ans);
		ans=0;
		pa=pb=pc=0;
	}	
	return 0;
}
