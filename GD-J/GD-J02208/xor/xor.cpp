#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 5 * 1e5 + 10;
int n , k , ans = 0;
int a[MAXN];
bool boo[MAXN];
int sum[MAXN];
int t[260];
struct node{
	int b , f;
};
bool cmp(node pre , node nxt){return pre.f - pre.b < nxt.f - nxt.b;}
vector <node> V;
int counter(int c , int d){
	int sum = a[c];
	for(int i=c+1;i<=d;i++){
		sum = sum | a[i];
	}
	return sum;
}
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i] = sum[i - 1] | a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int tmp=counter(i , j);
			if(tmp==k)
				V.push_back({i , j});
		}
	}
	sort(V.begin(),V.end(),cmp);
	for(auto now : V){
		bool flag = 0;
		for(int i=now.b;i<=now.f;i++)
			if(boo[i] == 1){
				flag = 1;
				break;
			}
		if(flag) continue;
		for(int i=now.b;i<=now.f;i++) boo[i] = 1;
		ans++;
	}
	printf("%d" , ans);
	return 0;
}
