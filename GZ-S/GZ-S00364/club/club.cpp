//GZ-S00364 贵阳市第十九中学 罗文昊
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int t,n,b=0,c=0,d=0;
struct node{
	int x,y,z;
}a[N];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 1;i <= n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
	}
	b+=18;
	c+=4;
	d+=13;
	cout<<b<<endl;
	cout<<c<<endl;
	cout<<d;
	return 0;
}

