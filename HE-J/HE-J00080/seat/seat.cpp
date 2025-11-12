#include<bits/stdc++.h>
using namespace std;
int a[110]={0};int n,m,xiaor;int mingci;int yl;
bool cmp(int x,int y){
	return x>y;
}
void chazhao(){
	for(int i = 1 ; i <= n*m ;i ++){
		if(a[i]==xiaor){
			mingci=i;
			break;
		}
	}
}
void dijilie(){
	if(mingci%n!=0){
		yl=mingci/n+1;
	}else{
		yl=mingci/n;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n*m ;i ++){
		cin>>a[i];
	}
	xiaor=a[1];
	sort(a+1,(a+1)+(n*m),cmp);
	chazhao();
	dijilie();
	// £”‡»À ˝
	int cnt=mingci-(yl-1)*n;
//	cout << cnt<<endl;
	if(yl%2==0){
		cout<<yl<<" "<<n-cnt+1;
	}else{
		cout<<yl<<" "<<cnt;
	}
	return 0;
}
