#include<bits/stdc++.h>
using namespace std;
int n,m,a[500],goal,cnt=1;
bool go_up=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	goal=a[1];
	sort(a+1,a+n*m+1,cmp);
	int c=1,r=1;//第c列第r行
	while(cnt<=n*m){
		if(a[cnt]==goal){
			cout<<c<<" "<<r;
			break;
		}
		if(r==n&&go_up==1){
			go_up=0;
			c++;
			cnt++;
			if(a[cnt]==goal){
				cout<<c<<" "<<r;
				break;
			}
		}
		if(r==1&&go_up==0){
			go_up=1;
			c++;
			cnt++;
			if(a[cnt]==goal){
				cout<<c<<" "<<r;
				break;
			}
		}
		if(go_up){
			r++;
		}else r--;
		cnt++;
	}

	return 0;
}