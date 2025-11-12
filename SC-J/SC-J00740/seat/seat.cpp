#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int num,idx;
}a[10001];
int n,m,cnt;
bool cmp(node x,node y){
	return x.num>y.num;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cnt++;
			cin >> a[cnt].num;
			a[cnt].idx=cnt;
		}
	}
	sort(1+a,1+cnt+a,cmp);
	int num;
	for(int i=1;i<=cnt;i++){
		if(a[i].idx==1){
			num=i;
			break;
		}
	}
	if(num==cnt){
		cout << n << " " << m;
	}else{
		if(num%n==0){
			cout << num/n << " ";
			if((num/n)%2==0){
				cout << 1;
			}else{
				cout << n;
			}
		}else{
			cout << num/n+1 << " ";
			if((num/n+1)%2==0){
				cout << n-num%n+1;
			}else{
				cout << num%n;
			}
		}
	}
	return 0;
}