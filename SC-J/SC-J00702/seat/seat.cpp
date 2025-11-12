#include<bits/stdc++.h>
#define int long long
using namespace std;
inline void read(int &x){
	x=0;char v=getchar();int f=1;
	while(v<'0'||v>'9'){
		if(v=='-') f=-1;
		v=getchar();
	}
	while(v>='0'&&v<='9'){
		x=(x<<1)+(x<<3)+(v&15);
		v=getchar();
	}
	x*=f;
}
const int N = 1000;
int n,m;
struct node{
	int val,id;
}a[N];
bool cmp(node x,node y){
	return x.val>y.val;
}
int len,sum,ansl=0,ansh=0;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	read(n),read(m);
	len=n*m;
	for(int i=1;i<=len;i++) read(a[i].val),a[i].id=i;
	sort(a+1,a+1+len,cmp);
	for(int i=1;i<=len;i++){
		if(a[i].id==1) sum=i;
	}
	ansl+=(sum/n);
	if(sum%n>=1) ansl++;
	if(ansl%2==0){
		int num=sum%n;
		if(num==0) num+=n;
		ansh=n-num+1;
	}else{
		int num=sum%n;
		if(num==0) num+=n;
		ansh=num;
	}
	printf("%lld %lld",ansl,ansh);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
