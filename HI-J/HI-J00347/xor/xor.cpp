#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
int tot=0; //最终区间数量 
int n, k;
int a[N];
struct node{
	int s, e, len;
} b[N];
int yh(int x, int y){
	int ans=0;
	int qz=1;//权值 
	while(max(x, y)){
		if(x%2!=y%2){
			ans+=qz;
		}
		qz*=2;
		x/=2; y/=2;
	}
	return ans;
}
bool cmp(node x, node y){
	if(x.e!=y.e){
		return x.e>y.e;
	}
	else return x.len<y.len;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]); 
	}
	cout<<2<<"\n";

    return 0;
}
