#include<iostream> 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
const int mx=1e5+10;
int t,n;
int man[mx];
struct node{
	int A,B,C;
}a[mx];
//bool cmp(node x,node y){
//	return x.A<y.A&&(x.A==y.A||x.B<y.B)&&(x.B==y.B||x.C<y.C);
//}
void solve(){
//	sort(a+1,a+n+1,cmp);
	int p,q,m;
	p=q=m=n/2;
	for(int i=1;i<=n;i++){
		if(p!=0&&q!=0&&m!=0){
			int _k=max(a[i].A,a[i].B);
			int k=max(a[i].C,_k);
			man[i]=man[i-1]+k;
			if(k==a[i].A) p--;
			else if(k==a[i].B) q--;
			else m--;
		}
		else if(p==0){
			int k=max(a[i].C,a[i].B);
			man[i]=man[i-1]+k;
			if(k==a[i].B) q--;
			else m--;
		}
		else if(q==0){
			int k=max(a[i].C,a[i].A);
			man[i]=man[i-1]+k;
			if(k==a[i].A) p--;
			else m--;
		}
		else{
			int k=max(a[i].A,a[i].B);
			man[i]=man[i-1]+k;
			if(k==a[i].A) p--;
			else q--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int maxn=n/2;
		for(int i=1;i<=n;i++){
				cin>>a[i].A>>a[i].B>>a[i].C;
		}
		solve();
		cout<<man[n]<<endl;
	}
	return 0;
}