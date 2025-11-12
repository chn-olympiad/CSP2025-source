#include<bits/stdc++.h>
using namespace std;
struct student{int id,g;}s[201];
inline bool cmp(student x,student y){
	return x.g>y.g;
}
int n,m,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;n*=m;
	for(int i=1;i<=n;i++){
		cin>>s[i].g;s[i].id=i;
	}
	sort(s+1,s+n+1,cmp);
	for(int i=n;i;i--)
		if(s[i].id==1){
			r=i;break;
		}
	if(r%m){
		cout<<r/m+1<<' ';
		if(r/m&1)cout<<m-r%m+1;
		else cout<<r%m;
	}else{
		cout<<r/m<<' ';
		if(r/m&1)cout<<m;
		else cout<<1;
	}
}
