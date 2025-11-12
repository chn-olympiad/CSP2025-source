#include<bits/stdc++.h>
using namespace std;
int n,m;
struct f2{
	int x,y;
}a[101];
struct f{
	int cheng,num;
}b[100001];
bool cmp(f x1,f x2){
	return x1.cheng>x2.cheng;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1,j=1,sum=1;;){
		if(sum>n*m){
			break;
		}
		a[sum].x=i,a[sum].y=j;
		sum++;
		if(j%2==1){
			if(i==n){
				j++;
			}else{
				i++;
			}
		}else{
			if(i==1){
				j++;
			}else{
				i--;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		cin>>b[i].cheng;
		b[i].num=i;
	}
	sort(b+1,b+1+n*m,cmp);
	int k=0;
	for(int i=1;i<=n*m;i++){
		if(b[i].num==1){
			k=i;
			break;
		}
	}
	cout<<a[k].y<<" "<<a[k].x;
}

