#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x > y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cnt = n * m ;
	int cnt1 = n + n;
	int a[cnt],b[cnt1];
	for(int i = 0;i<cnt;i++){
		cin>>a[i];
	}
	int r = a[0]; 
	sort(a,a+cnt,cmp);
	int idx = 0;
	for(int i = 0;i<cnt;i++){
		if(r == a[i]){
			idx = i + 1;
			break;
		}
	}
	for(int i = 1;i<=n;i++){
		b[i] = i;
	}
	int x = n + 1;
	for(int j = n;j>=1;j--){
		b[x] = j;
		x++;
	} 
	for(int i = 1;;i++){
		if(i*n >= idx){
			cout<<i;
			int temp = b[idx % cnt1];
			cout<<" "<<temp;
			break;
		}
	}
	return 0;
} 
