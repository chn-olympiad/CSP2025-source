#include<bits/stdc++.h>
#define ll long long
using std::cout;
using std::cin;
using std::endl;
const int N=1e5+50;
ll T,n,ans,k1,k2,k3;
struct node{
	int l1,l2,l3,maxa,mida,mina,less;
}a[N];
int maxx(int x,int y,int z){
	if(x>=y&&x>=z){
		return 1;
	}if(y>=x&&y>=z){
		return 2;
	}if(z>=y&&z>=x){
		return 3;
	}
}
bool cmp(node x,node y){
	return x.less<y.less;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0,k1=0,k2=0,k3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].l1>>a[i].l2>>a[i].l3;
			int a1;
			a1=maxx(a[i].l1,a[i].l2,a[i].l3);
			if(a1==1){
				k1++,ans+=a[i].l1;
				a[i].maxa=a[i].l1;
				if(a[i].l2>a[i].l3)a[i].mida=a[i].l2,a[i].mina=a[i].l3;
				else a[i].mida=a[i].l3,a[i].mina=a[i].l2;
			}if(a1==2){
				k2++,ans+=a[i].l2;
				a[i].maxa=a[i].l2;
				if(a[i].l1>a[i].l3)a[i].mida=a[i].l1,a[i].mina=a[i].l3;
				else a[i].mida=a[i].l3,a[i].mida=a[i].l1;
			}if(a1==3){
				k3++,ans+=a[i].l3;
				a[i].maxa=a[i].l3;
				if(a[i].l1>a[i].l2)a[i].mida=a[i].l1,a[i].mina=a[i].l2;
				else a[i].mida=a[i].l2,a[i].mina=a[i].l1;
			}a[i].less=a[i].maxa-a[i].mida;
		}
		//ÊäÈë+Ô¤´¦Àí
		::std::sort(a+1,a+n,cmp);
		if(k1>n/2){
			int u=k1-(n/2);
			for(int i=1;i<=u;i++){
				if(a[i].maxa==a[i].l1)
				ans-=a[i].less;
				else u++;
			}cout<<ans<<endl;
			continue;
		}if(k2>n/2){
			int u=k2-(n/2);
			for(int i=1;i<=u;i++){
				if(a[i].maxa==a[i].l2)
				ans-=a[i].less;
				else u++;
			}cout<<ans<<endl;
			continue;
		}if(k3>n/2){
			int u=k3-(n/2);
			for(int i=1;i<=u;i++){
				if(a[i].maxa==a[i].l3)
				ans-=a[i].less;
				else u++;
			}cout<<ans<<endl;
			continue;
		}cout<<ans<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
