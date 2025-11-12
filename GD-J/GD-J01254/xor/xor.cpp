#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=5e5+5;
int n,k,ans,top=0;
int a[maxn];
struct XOR{
	int num,id;
}x[maxn];//x前缀异或 
struct qj{
	int l,r;
}q[3*maxn];
int find(int l,int r,int y){//找第一个大于 y 的下标 
	while(l+1<r){
		int mid=l+(r-l)/2;
		if(x[mid].num<=y)l=mid;
		else r=mid;
	}
	return min(r,n);
}
void push(int l,int r){
	if(l>r)swap(l,r);
	//printf("push [%d,%d]\n",l,r);
	top++;
	q[top].l=l;
	q[top].r=r;
}
void minpush(int i,int l,int r){
	if(i<l)push(i+1,l);
	else push(l+1,i);
	if(i<r)push(i+1,r);
	else push(r+1,i);
}
bool cmp1(XOR x,XOR y){
	if(x.num!=y.num)return x.num<y.num;
	return x.id<y.id;
}
bool cmp2(qj x,qj y){
	return x.r<y.r;//按右端点排序 
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==k)push(i,i);
		x[i].num=x[i-1].num^a[i];
		x[i].id=i;
		if(x[i].num==k)push(1,i);
	}
	sort(x+1,x+n+1,cmp1);//x_{l-1}⊕x_r = x_r⊕x_{l-1}
	//for(int i=1;i<=n;i++)printf("%d ",x[i].id);
	for(int i=1;i<=n;i++){
		int l=find(i,n,x[i].num^k-1);//x^y=k, x^k=y
		int r=find(i,n,x[i].num^k);
		if(l<r){//如果有多个区间，只放最短的 
			minpush(x[i].id,x[l].id,x[r-1].id);
		}
	}
	sort(q+1,q+top+1,cmp2);//区间排序 
	int r=0;
	for(int i=1;i<=top;i++){
		if(q[i].l>r){
			ans++;
			r=q[i].r;
		}
	}
	printf("%d",ans);
	return 0;
}
