#include<bits/stdc++.h>
using namespace std;
int n,m;
struct acb{
	int f,id;
}a[1009];
bool cmp(acb x,acb y){
	return x.f>y.f;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i].f;
		a[i].id=i+1;
	}
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i].id==1){
			int x=i+1;
			if(x<=m)cout<<1<<" "<<x;
			else{
				if(x%m==0){
					if((x/m)%2==0)cout<<x/m<<" "<<1;
					else cout<<x/m<<" "<<m;
				}
				else{
					if((x/m)%2!=0)cout<<x/m+1<<" "<<m-x%m+1;
					else cout<<x/m+1<<" "<<x%m;
				}
				
			}
			break;
		}
	}
	return 0;
}

