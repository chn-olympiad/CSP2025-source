#include<bits/stdc++.h> 
using namespace std;

struct stud{
	int c1,c2,c3;
}a[1000000];
int ansk;
void kl(int ind,int n,int s,int k1,int k2, int k3){
	int l = n/2;
	if(k1>l || k2 > l || k3 > l) return;
	if(ind == n-1){
		if(k1 < n/2) ansk = max(ansk,s + a[ind].c1);
		if(k2 < n/2) ansk = max(ansk,s + a[ind].c2);
		if(k3 < n/2) ansk = max(ansk,s + a[ind].c3);
	}
	else{
		kl(ind+1,n,s+a[ind].c1,k1+1,k2,k3);
		kl(ind+1,n,s+a[ind].c2,k1,k2+1,k3);
		kl(ind+1,n,s+a[ind].c3,k1,k2,k3+1);
	}
}

bool cmpBC(stud com1,stud com2){
	return com1.c1 > com2.c1;
}

bool cmpAB(stud com1,stud com2){
	return com1.c1-com1.c2 > com2.c1-com2.c2;
}

bool cmpABC(stud com1,stud com2){
	return com1.c1+com1.c2+com1.c3 > com2.c1+com2.c2+com2.c3;
}

//bool cmp;

int t;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		int n;
		memset(a,sizeof(a),0);
		cin >> n;
		bool flag[2] = {1,1};
		int t1,t2,t3;
		for(int i=0;i<n;i++){
			cin >> t1 >> t2 >> t3;
			if(flag[0] && t2) flag[0] = 0;
			if(flag[1] && t3) flag[1] = 0;
			a[i].c1 = t1;
			a[i].c2 = t2;
			a[i].c3 = t3;
		}
		
		
			
		if(flag[1]){
			if(flag[0]){
				int ans = 0;
				sort(a,a+n,cmpBC);
				for(int i=0;i<n/2;i++)
					ans += a[i].c1;
				cout << ans << endl;
				continue;
			}
			else{
				int ans = 0;
				sort(a,a+n,cmpAB);
				for(int i=0;i<n/2;i++) ans += a[i].c1;
				for(int i=n/2;i<n;i++) ans += a[i].c2;
				cout << ans << endl;
				continue;
			} 
		}
		else{
			ansk = 0;
			int c1m=0,c2m=0,c3m=0;
			kl(0,n,0,0,0,0);
			cout << ansk << endl;
		}
		
	}
	return 0;
}

