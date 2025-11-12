#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const long long M = 998244353;
int n;
int a[N],sum[N];
//long long C[N][N];
long long cnt;
//void init(){
//	for(int i=1;i<=n;i++){
//		C[i][0] = C[i][i] = 1;
//		for(int j=1;j<i;j++){
//			C[i][j] = (C[i][j-1]+C[i-1][j-1])%M;
//			cout << C[i][j] << " ";
//		}cout << endl;
//	}
//}
bool cmp(int a,int b){
	return a>b;
}
//int f1(int pos,int len,int goal){//”“∂Àµ„ 
//	int l = pos+len, r = n, mid, ans=-1;
//	while(l<=r){
//		int mid = l+r >> 1;
//		cout << "mid" << mid << endl;
//		int s = sum[mid]-sum[mid-len];
//		cout << "sum" << s << endl;
//		if(s > goal) l = mid+1,ans=mid;
//		else{
//			r = mid-1;
//		}
//	}
//	return ans;
//}
//int f2(int r,int len,int goal){
//	int l = r-len+1, mid;
//	int p = a[r+1], s = sum[r]-sum[l-1], ans=0;
//	while(l<=r){
//		mid = l+r >> 1;
//		if(s-a[mid]+p > goal){
//			r = mid-1;
//			if(a[ans]!=a[mid]) ans = mid;
//			else if(ans > mid) ans = mid;
//		}
//		else l = mid+1;
//	}
//	return ans;
//}
//int f3(int l,int r,int s,int g){
//	int mid, ans;
//	while(l<=r){
//		mid = l+r >> 1;
//		if(s+a[mid] > mid){
//			ans = mid;
//			r = mid-1;
//		}
//		else l = mid+1;
//	}
//	return ans;
//}
void dfs(int pos,int mx,int s,int len){
	
	if(len >= 3){
		if(s>mx)
		cnt++;
	}
	for(int i=pos;i<=n;i++){
		dfs(i+1,mx,s+a[i],len+1);
	}
}
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
//	init();
	sort(a+1,a+1+n,cmp);
//	for(int i=1;i<=n;i++) sum[i] = sum[i-1]+a[i];
//	for(int i=1;i<=n;i++){
//		cout << cnt << endl;
//		int g = a[i], s = a[i];
//		cout << "g" << g << endl;
//		for(int len=2;i+len-1<=n;len++){
//			int pos1 = f1(i,len,g); // //”“∂Àµ„  
//			if(pos1==-1) continue;
//			cnt = (cnt+C[pos1-i][len]) % M;
//			cout <<cnt << "=" << endl;
//			int l = pos1-len+1;
//			if(pos1==i+len)  continue;
//			int pos2 = f2(pos1,len,s);
//			if(pos2==-1) continue;
//			cnt = (cnt+(pos1-pos2+1)*(l-i-1))%M;
//			cout << cnt  << "-" << endl;
//			long long k = sum[pos1]-sum[pos1-len]-a[pos2];
//			int pos3 = f3(i+1,l-1,k,g);
//			if(pos3==-1) continue;
//			if(pos2!=l) cnt = (cnt+l-pos3+1);
//			cout << cnt << "*" << endl;
//		}
//	}
for(int i=1;i<=n-2;i++) dfs(i+1,a[i]*2,a[i],1);
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
