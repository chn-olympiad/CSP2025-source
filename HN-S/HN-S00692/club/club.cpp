#include<bits/stdc++.h>
using namespace std;
#define IO(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
const int N =1e5 + 7;
int ans;
int f[4];
struct e{
	int a[4];
	int m,i;
};
vector<e> a,b; 
int n;
int t;
bool c(e x,e y){
	return x.m>y.m;
}
void init(){
	a.clear();
	b.clear();
	ans=0;
	f[1]=f[2]=f[3]=0;
	scanf("%d",&n);
	a.resize(n+1);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].a[1],&a[i].a[2],&a[i].a[3]);
		if(a[i].a[1]>=a[i].a[2] && a[i].a[1]>=a[i].a[3]) a[i].m=a[i].a[1],a[i].i=1;
		if(a[i].a[2]>=a[i].a[1] && a[i].a[2]>=a[i].a[3]) a[i].m=a[i].a[2],a[i].i=2;
		if(a[i].a[3]>=a[i].a[2] && a[i].a[3]>=a[i].a[1]) a[i].m=a[i].a[3],a[i].i=3;
	}
	sort(a.begin()+1,a.end(),c);
	for(int i=1;i<=n;i++){
		if(f[a[i].i]==n/2) b.push_back(a[i]);
		else{
			f[a[i].i]++;
			ans+=a[i].m;
		}
	}
	for(int i=0;i<b.size();i++){
		if(max(b[i].a[1],b[i].a[3])>=b[i].a[2] && b[i].a[2]>=min(b[i].a[1],b[i].a[3]) && b[i].i!=2){
			ans+=b[i].a[2];
			continue;
		} 
		if(max(b[i].a[2],b[i].a[3])>=b[i].a[1] && b[i].a[1]>=min(b[i].a[2],b[i].a[3]) && b[i].i!=1){
			ans+=b[i].a[1];
			continue;
		} 
		if(max(b[i].a[1],b[i].a[2])>=b[i].a[3] && b[i].a[3]>=min(b[i].a[1],b[i].a[2]) && b[i].i!=3){
			ans+=b[i].a[3];
			continue;
		} 
	}
	printf("%d\n",ans);
}
int main(){
	IO("club");
	scanf("%d",&t);
	while(t--) init();
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

