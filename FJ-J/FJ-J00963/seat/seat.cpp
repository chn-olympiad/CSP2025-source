#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,h,l;
struct x{
	int f,w;
}a[105];
bool cmp(x o,x t){
	return o.f>t.f;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].f;
		a[i].w=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(i%n==1){
			cnt++;
			l++;
			if(cnt%2==1){
				h=1;
			}else{
				h=n;
			}
		}else{
			if(cnt%2==1){
				h++;
			}else{
				h--;
			}
		}
		if(a[i].w==1){
			cout<<l<<" "<<h;
			return 0;
		}
	}
	return 0;
}

