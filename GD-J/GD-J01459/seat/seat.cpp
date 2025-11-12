#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int n,m,a[107],num;
int c=1,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++) cin>>a[i];
	num=a[1];
	sort(a+1,a+1+len,cmp);
	for(int i=1;i<=len;i++){
		if(c%2==1){
			r++;
			if(r>n){
				r--;
				c++;
			}
		}else{
			r--;
			if(r==0){
				r++;
				c++;
			}
		}
		if(a[i]==num) return cout<<c<<' '<<r,0;
	}
	return 0;
}

