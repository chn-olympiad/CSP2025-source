#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long t,n,a[N],b[N],c[N],bigg,xian; 
void dfs(int k,int ap,int bp,int cp,long long summ){
	if(k == n){
		bigg = max(bigg,summ);
		return ;
	}
	if(ap < xian) dfs(k+1,ap+1,bp,cp,summ+a[k+1]);
	if(bp < xian) dfs(k+1,ap,bp+1,cp,summ+b[k+1]);
	if(cp < xian) dfs(k+1,ap,bp,cp+1,summ+c[k+1]);
}
bool op(int aa,int bb){
	return aa > bb;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		bigg = 0;
		xian = n / 2;
		for(int i = 1;i <= n;i++){
			scanf("%d",&a[i]);
			scanf("%d",&b[i]);
			scanf("%d",&c[i]);
		}
		if(n <= 15){
			dfs(0,0,0,0,0);
			cout << bigg << endl;
		}else{
			sort(a+1,a+n+1,op);
			for(int i = 1;i <= xian;i++)
				bigg += a[i];
			cout << bigg << endl;
		}	
	}
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}

