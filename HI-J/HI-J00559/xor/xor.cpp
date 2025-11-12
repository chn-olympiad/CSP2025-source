#include<bits/stdc++.h>
using namespace  std;
const int N = 5*1e5+10;
int a[N], pre[N];
struct node{
	int x,y;
}t[1000006];
bool cmp(node kk, node kkk){
	return kk.y < kkk.y;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	int top = 0;
	cin >> n >> k;
	for(int i = 1; i<=n;i++){
		scanf("%d", &a[i]);
		if(i == 1) pre[i]=a[i];
		else pre[i] = a[i]^pre[i-1];
	}
	int ll = 0, rr  = 0;
	for(int i = n; i >= 1; i--){
		if(i < ll){
			for(int j = i; j <= rr;j++){
				int y = pre[j]^pre[i-1];
				if(y == k){
					ll = i, rr = j;
					t[++top].x = i;
					t[top].y = j;
					break;
				}
			} 
		}else {
			for(int j = i; j <= n;j++){
				int y = pre[j]^pre[i-1];
				if(y == k){
					ll = i, rr = j;
					t[++top].x = i;
					t[top].y = j;
					break;
				}
			} 
		}
	}
	sort(t+1,t+top+1, cmp);
	int las = 0, ans = 0;
	for(int i = 1; i <= top; i++){
		if(t[i].x > las) {
			las = t[i].y;
			ans++; 
		}
	}
	cout << ans;
	return 0;
} 
