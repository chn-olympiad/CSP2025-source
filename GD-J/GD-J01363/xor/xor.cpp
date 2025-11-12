#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n, k, ans, len;
int a[maxn];
struct node_t{
	int l;
	int r;
}ans_list[maxn];
bool cmp(node_t num1, node_t num2){
	if(num1.r==num2.r) return num1.l<num2.l;
	else return num1.r<num2.r;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		for(int r=1;r<=n;r++){
			int num=0;
			for(int i=l;i<=r;i++){
				num=num^a[i];
			}
			if(num==k){
				ans_list[++len].l=l;
				ans_list[len].r=r;
			}
		}
	}
	sort(ans_list+1, ans_list+1+len, cmp);
	int l, r;
	if(len>=1){
		l=ans_list[1].l;
		r=ans_list[1].r;
		ans++;
	}
	for(int i=2;i<=len;i++){
		if(ans_list[i].l>r){
			ans++;
			r=ans_list[i].r;
			l=ans_list[i].l;
		}
	}
	cout<<ans;
	
	return 0;
}
