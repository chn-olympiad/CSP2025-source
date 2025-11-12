#include <bits/stdc++.h>
using namespace std;
const int MAXN=500005;
struct xo{
	int st,en;
}rj[500005];
int n,k,ans=0;
int a[MAXN],sum[MAXN];
bool che[MAXN]; 
bool cmp(xo x,xo y){
	return x.en<y.en; 
}
bool ck(int x,int y){
	for(int i=x;i<=y;i++){
		if(che[i]==1){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sum[0]=0;
	sum[1]=a[1];
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]^a[i];
		//cout << sum[i] << " ";	
	}
	cout << endl;
	int u=1;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if(l>r){
				break;
			}
			if(l==1){
				if(sum[r]==k){
					rj[u].st=l;
					rj[u].en=r;  
					//cout << l << " " << r <<endl; 
					u++; 
				}
			}else if((sum[r]^sum[l-1])==k){
				rj[u].st=l;
				rj[u].en=r;  
				int p=sum[r]^sum[l-1];
				//cout << p <<" "<<l << " " << r <<endl; 
				u++; 
			}
		}
	}
	sort(rj+1,rj+u+1,cmp);
	for(int i=1;i<=u;i++){
		if(ck(rj[i].st,rj[i].en)==1){
			//cout <<i << " "<<rj[i].st << " " << rj[i].en << endl;
			if(rj[i].st!=0&&rj[i].en!=0){
				ans++;
			}
			for(int j=rj[i].st;j<=rj[i].en;j++){
				che[j]=1;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
/*
4 2
2 1 0 3
4 3
2 1 0 3
4 0
2 1 0 3
100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1
*/
