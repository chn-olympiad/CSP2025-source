#include<bits/stdc++.h>
using namespace std;
int n,k,ma,num,aaa[500005],n2;
bool tf[500005],tf2;
struct sss{
	int l,r=99999999,jz;
}a[500005];
bool cmp2(const sss x,const sss y){
	if(x.r==99999999){
		return false;
	}
	if(y.r==99999999){
		return true;
	}
	if(x.jz<y.jz){
		return true;
	}else if(x.jz==y.jz){
		if(x.r-x.l<y.r-y.l){
			return true;
		}
		return false;
	}
	return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(tf,true,sizeof(tf));
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&aaa[i]);
	}
	for(int i=1;i<=n;i++){
		a[i].l=i;
		num=0;
		for(int j=i;j<=n;j++){
			num=(num xor aaa[j]);
			if(num==k){
				a[i].r=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((a[i].l<a[j].l && a[i].r>a[j].l) or (a[i].l<a[j].r && a[i].l>a[j].l)){
				a[i].jz++;
			}
		}
	}
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i++){
		tf2=true;
		if(a[i].r==99999999){
			break;
		}
		for(int j=a[i].l;j<=a[i].r;j++){
			if(tf[j]!=true){
				tf2=false;
				break;
			}
		}
		if(tf2==true){
			ma++;
			for(int j=a[i].l;j<=a[i].r;j++){
				tf[j]=false;
			}
		}
	}
	printf("%d",ma);
	return 0;
}
