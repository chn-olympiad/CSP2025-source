#include<bits/stdc++.h>
using namespace std;
struct st{
	int s;
	int num;
}a[10000001];
bool cmp(st x,st y){
	return x.num>y.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num;a[i].s=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int c=1,r=0;
	for(int i=1;i<=n*m;i++){
		if(c%2==1) r++; else r--;
		if(r>n&&c%2==1){
			c++;r--;
		}
		if(r<1&&c%2==0){
			c++;r++;
		}
		if(a[i].s==1) break;
	}cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
