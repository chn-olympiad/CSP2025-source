#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int t,n,sum[5];
int xian;
ll ans;
struct node{
	int a,b,c;
	int ch;
}a[N];
bool cmpa(node xx,node yy){
	int xc=min(xx.a-xx.b,xx.a-xx.c);
	int yc=min(yy.a-yy.b,yy.a-yy.c);
	return xc<yc;
}
bool cmpb(node xx,node yy){
	int xc=min(xx.b-xx.a,xx.b-xx.c);
	int yc=min(yy.b-yy.a,yy.b-yy.c);
	return xc<yc;
}
bool cmpc(node xx,node yy){
	int xc=min(xx.c-xx.b,xx.c-xx.a);
	int yc=min(yy.c-yy.b,yy.c-yy.a);
	return xc<yc;
}
void chose(int i){
	int num=0;
	if(a[i].a>a[i].b&&a[i].a>a[i].c){
		num=1;
		ans+=a[i].a;
	}else if(a[i].b>a[i].a&&a[i].b>a[i].c){
		num=2;
		ans+=a[i].b;
	}else{
		num=3;
		ans+=a[i].c;
	}
	a[i].ch=num;
	sum[num]++;
	return;
}
int main(){

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		//clear
		memset(a,0,sizeof(a));
		sum[1]=sum[2]=sum[3]=0;
		ans=0;
		//code
		cin>>n;
		xian=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			chose(i);
		}
		if(sum[1]<=xian&&sum[2]<=xian&&sum[3]<=xian){
			cout<<ans<<"\n";
		}else if(sum[1]>xian){
			sort(a+1,a+n+1,cmpa);
			int chao=sum[1]-xian;
			for(int i=1;i<=chao;i++){
				ans=ans-min(a[i].a-a[i].b,a[i].a-a[i].c);
			}
			cout<<ans<<"\n";
		}else if(sum[2]>xian){
			sort(a+1,a+n+1,cmpb);
			int chao=sum[2]-xian;
			for(int i=1;i<=chao;i++){
				ans=ans-min(a[i].b-a[i].a,a[i].b-a[i].c);
			}
			cout<<ans<<"\n";
		}else if(sum[3]>xian){
			sort(a+1,a+n+1,cmpc);
			int chao=sum[3]-xian;
			for(int i=1;i<=chao;i++){
				ans=ans-min(a[i].c-a[i].b,a[i].c-a[i].a);
			}
			cout<<ans<<"\n";
		}
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
