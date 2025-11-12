#include<bits/stdc++.h> 
using namespace std;
struct Node{
	int shu,wei;
};
struct node{
	Node a1,a2,a3;
}a[100010];
bool cmp(node p,node q){
	return p.a1.shu-p.a2.shu>q.a1.shu-q.a2.shu||(p.a1.shu-p.a2.shu==q.a1.shu-q.a2.shu&&p.a2.shu-p.a3.shu>=q.a2.shu-q.a3.shu);
}
int read(){
	char ch;
	int ans = 0;
	ch = getchar();
	while(ch<='9'&&ch>='0'){
		ans = ans*10+(ch-'0');
		ch = getchar();
	}
	return ans;
}
long long t,n,ji[4],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t = read();
	while(t--){
		ji[1] = 0;
		ji[2] = 0;
		ji[3] = 0;
		ans = 0;
		n = read();
		for(long long i = 1;i<=n;i++){
			a[i].a1.shu = read();
			a[i].a2.shu = read();
			a[i].a3.shu = read();
		}
		for(long long i = 1;i<=n;i++)a[i].a1.wei = 1,a[i].a2.wei = 2,a[i].a3.wei = 3;
		for(long long i = 1;i<=n;i++){
			if(a[i].a1.shu<a[i].a2.shu)swap(a[i].a1,a[i].a2);
			if(a[i].a2.shu<a[i].a3.shu)swap(a[i].a2,a[i].a3);
			if(a[i].a1.shu<a[i].a2.shu)swap(a[i].a1,a[i].a2);
		}
		sort(a+1,a+n+1,cmp);
		for(long long i = 1;i<=n;i++){
			if(ji[a[i].a1.wei]+1<=n/2)ji[a[i].a1.wei]++,ans+=a[i].a1.shu;
			else ji[a[i].a2.wei]++,ans+=a[i].a2.shu;
		}
		cout<<ans<<"\n";
	}
	
}
