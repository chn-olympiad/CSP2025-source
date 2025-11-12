#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=5e5+5;
int n,k,ans;
int a[maxn],pre[maxn],tot;
struct choice{
	int l,r;
}len[100000005];
bool cmp(choice a,choice b){
	return a.r<=b.r;
}
void solve1(){
	int now;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j){
				now=a[i];
			}
			else{
				now^=a[j];
			}
			if(now==k){
				len[++tot]={i,j};
				break;
			}
		}
	}
	sort(len+1,len+tot+1,cmp);
	int R=len[1].r;
	ans++;
	for(int i=2;i<=tot;i++){
		if(len[i].l>R){
			ans++;
			R=len[i].r;
		}
	}
	cout<<ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	solve1();
	return 0;
}
