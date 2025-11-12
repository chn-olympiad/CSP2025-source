#include <bits/stdc++.h>
using namespace std;
long long  n,m,k,s,t,sum[4],ans;

struct node{
	int id,a;
};

struct kop{
	node a[4];
	int ma,mi,ml;
}kl[1000005];

bool cmp(node p,node q){
	return p.a>q.a;
}
bool klp(kop e,kop r){
	return e.ma>r.ma;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n ;memset(sum,0,sizeof(sum));
		for(int i =1;i<=n;i++){
			cin >> kl[i].a[1].a >> kl[i].a[2].a >>kl[i].a[3].a;
			kl[i].a[1].id = 1;kl[i].a[2].id = 2;
			kl[i].a[3].id = 3;
			sort(kl[i].a+1,kl[i].a+4,cmp);	
			kl[i].ma = kl[i].a[1].a-kl[i].a[2].a;
		}
		sort(kl+1,kl+1+n,klp);
		for(int i =1;i<=n;i++){
			if(sum[kl[i].a[1].id] < n /2){ 
				sum[kl[i].a[1].id]++; 
				ans+=kl[i].a[1].a;
			}
			else {
				sum[kl[i].a[2].id]++;
				ans+=kl[i].a[2].a;
			}
			
		}
		cout << ans <<"\n";ans= 0;
	}
	
	
	return 0;
	
} 
