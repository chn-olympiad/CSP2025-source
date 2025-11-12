#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm> 
using namespace std;

const int maxn=5e5+10; 
struct qj{
	int first,end;
}g_tnt[maxn];
int a[maxn];
bool g_cmp(qj a,qj b){
	if (a.end!=b.end)return a.end<b.end;
	else return a.first>b.first;
}
int main(){
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long k;
	cin >>n>>k;
	int cnt=0;
	for (int i=1;i<=n;i++)cin >>a[i];
	for (int i=1;i<=n;i++){
		long long ik=0;
		for (int j=i;j<=n;j++){
			ik^=a[j];
			if (ik==k){
				cnt++;
				g_tnt[cnt].first=i;g_tnt[cnt].end=j;
			
				break;
			}
		}
	}
	
	sort(g_tnt+1,g_tnt+1+cnt,g_cmp);
	int ans=0,nowend=0;
	for (int i=1;i<=cnt;i++){
		if (g_tnt[i].first>nowend){
			
			ans++;
			nowend=g_tnt[i].end;
		}
	}
	cout <<ans;
	

	return 0;
} 
