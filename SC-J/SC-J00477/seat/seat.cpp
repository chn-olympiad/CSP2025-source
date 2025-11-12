#include<bits/stdc++.h>
using namespace std;
struct ins{
	int ren;
	int chen;
};
ins a[111];
bool pai(ins x,ins b){
	return x.chen>b.chen;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].chen;
		a[i].ren=i;
	}
	sort(a+1,a+n*m+1,pai);
	int x=1;
	int y=1;
	int i=1;
	int jia=1;
	while(a[i].ren!=1){
		i++;
		if(x==n && jia!=-1){
			jia=-1;
			y++;
		}else
		if(x==1 && jia!=1){
			jia=1;
			y++;
		}else
		x+=jia;
	}
	cout<<y<<" "<<x;
	return 0;
}