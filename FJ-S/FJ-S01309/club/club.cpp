#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5; 
int T,n;
struct node{
	int A,B,C,M,val;
}a[N];
inline bool cmp(node a,node b){
	return a.val>b.val;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> T;
	while(T--){
		cin >> n;
		int A=0,B=0,C=0,ans=0,up=n/2;
		for(int i=1;i<=n;i++){
			cin >> a[i].A >> a[i].B >> a[i].C ;
			if(a[i].A>=a[i].B&&a[i].B>=a[i].C) a[i].M=1,ans+=a[i].A;
			else if(a[i].A>=a[i].C&&a[i].C>=a[i].B) a[i].M=1,ans+=a[i].A;
			else if(a[i].B>=a[i].A&&a[i].A>=a[i].C) a[i].M=2,ans+=a[i].B;
			else if(a[i].B>=a[i].C&&a[i].C>=a[i].A) a[i].M=2,ans+=a[i].B;
			else if(a[i].C>=a[i].A&&a[i].A>=a[i].B) a[i].M=3,ans+=a[i].C;
			else if(a[i].C>=a[i].B&&a[i].B>=a[i].A) a[i].M=3,ans+=a[i].C;
			
			if(a[i].M==1) A++,a[i].val=max(a[i].B-a[i].A,a[i].C-a[i].A);
			else if(a[i].M==2) B++,a[i].val=max(a[i].C-a[i].B,a[i].A-a[i].B);
			else C++,a[i].val=max(a[i].B-a[i].C,a[i].A-a[i].C);
		}
		sort(a+1,a+n+1,cmp);
		//for(int i=1;i<=n;i++) cout << a[i].M << " " << a[i].A << " " << a[i].B << " " << a[i].C << " " << a[i].val << "\n"; 
		//cout << ans << "ans!\n";
		for(int i=1;i<=n;i++){
			if(A<=up&&B<=up&&C<=up) break;
			if(A>up){
				//cout << "inA\n";
				if(a[i].M!=1) continue;
				ans+=a[i].val;
				A-=1;
			}else if(B>up){
				//cout << "inB\n";
				if(a[i].M!=2) continue;
				ans+=a[i].val;
				B-=1;
			}else{
				//cout << "inC\n";
				if(a[i].M!=3) continue;
				ans+=a[i].val;
				C-=1;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
