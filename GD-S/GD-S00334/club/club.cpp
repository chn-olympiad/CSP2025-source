#include<bits/stdc++.h>
using namespace std;
struct data1{
	long long x,xi;
};
struct data2{
	long long x[4];
}a[20001];
bool cmp1(data1 a,data1 b){
	return a.x>b.x; 
}
bool cmp2(data2 a,data2 b){
	return max(a.x[1],max(a.x[2],a.x[3]))>max(b.x[1],max(b.x[2],b.x[3]));
}
long long T,n,sum,vis[10];
int main(){
	freopen("club.in","r",stdin);
	freopen("clud.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i].x[j]);
			} 
		}
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++){
			data1 arr[4];
			for(int j=1;j<=3;j++){
				arr[j].x = a[i].x[j];
				arr[j].xi = j; 
			}
			sort(arr+1,arr+4,cmp1);
			for(int j=1;j<=3;j++){
				if(vis[arr[j].xi]<n/2){
					sum+=arr[j].x;
					vis[arr[j].xi]++;
					break;
				}
			}
		}
		cout << sum << endl;
		sum=0;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

