#include<bits/stdc++.h>
using namespace std;
long long n,ans,aaa,bbb,ccc;
struct qw{
	int a,b,c,maxn,num;
}a[100010];
bool cmp(qw x,qw y){
	if(x.maxn!=y.maxn)
		return x.maxn<y.maxn;
	return x.num<y.num;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;bool cx=1,bx=1;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
		a[i].maxn=max(a[i].a,max(a[i].b,a[i].c));
		if(a[i].b>0) bx=1;
		if(a[i].c>0) cx=1;
	}
	sort(a+1,a+1+n,cmp);
	if(bx==1&&cx==1){
		for(int i=1;i<=n/2;i++){
			ans+=a[i].maxn;
		}
		cout<<ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
