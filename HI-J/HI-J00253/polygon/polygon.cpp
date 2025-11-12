#include<bits/stdc++.h> //this is 64pts
using namespace std;
int n,a[505],ans;
const int MOD=998244353;
void dfs(int size,int i,long long sum,int maxx,int go){
	//cout << size << ' ' << i << ' ' << sum << ' ' << maxx << ' ' << go << endl;
	if (i==size){
		//cout << "Make a return: " << sum << ' ' << maxx << endl;
		if (sum>maxx*2) ans=(ans+1)%MOD;
		return;
	}for(int o=go+1;o<=n-(size-i)+1;o++){
		int sas=(maxx<a[o])?a[o]:maxx;
		dfs(size,i+1,sum+a[o],sas,o);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	bool flag=true;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i]>1) flag=false;
	}if (flag==true){ //more 24 pts
		long long anss=0;
		for(int i=1;i<=n-2;i++){
			anss=(anss+i*(n-1-i))%MOD;
		}printf("%d",anss%MOD);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=3;i<=n;i++){ 
		for(int j=1;j<=n-i+1;j++)
			dfs(i,1,a[j],a[j],j);
	}printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}/*when i check my cpp, i found 10+ mistake. 

i really think it is a suck problem, because just while can get 40pts, and use your mind can get other 24pts.*/
