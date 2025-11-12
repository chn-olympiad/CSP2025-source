#include<bits/stdc++.h>
using namespace std;
struct asd{
	int a,b,c;
};
int maxes(int a,int b,int c){
	if(a>b&&a>c)return 1;
	if(b>a&&b>c)return 2;
	return 3;
}
int maes(int a,int b,int c){
	if(a>b&&a<c)return 1;
	if(a>c&&a<b)return 1;
	if(b>a&&b<c)return 2;
	if(b>c&&b<a)return 2;
	return 3;
}
int mes(int a,int b,int c){
	if(a>b&&c>b)return 2;
	if(b>a&&c>a)return 1;
	return 3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
 	int n,a[4][2]={0};
		cin>>n;
		asd qqq[100000];
		for(int i=1;i<=n;i++){
			cin>>qqq[i].a>>qqq[i].b>>qqq[i].c;
			a[maxes(qqq[i].a,qqq[i].b,qqq[i].c)][0]+=qqq[i].a;
			a[maxes(qqq[i].a,qqq[i].b,qqq[i].c)][1]+=1;
			if(a[maxes(qqq[i].a,qqq[i].b,qqq[i].c)][1]>(n/2)){
				a[maxes(qqq[i].a,qqq[i].b,qqq[i].c)][0]-=qqq[i].a;
				a[maes(qqq[i].a,qqq[i].b,qqq[i].c)][1]+=a[maxes(qqq[i].a,qqq[i].b,qqq[i].c)][1]-=1;
				a[maes(qqq[i].a,qqq[i].b,qqq[i].c)][0]+=qqq[i].b;
				if(a[maes(qqq[i].a,qqq[i].b,qqq[i].c)][1]>(n/2)){
					a[maes(qqq[i].a,qqq[i].b,qqq[i].c)][0]-=qqq[i].b;
					a[maes(qqq[i].a,qqq[i].b,qqq[i].c)][1]-=a[mes(qqq[i].a,qqq[i].b,qqq[i].c)][1]+=1;
					a[mes(qqq[i].a,qqq[i].b,qqq[i].c)][0]+=qqq[i].c;
				}
			}	
		}
		cout<<a[1][0]+a[2][0]+a[3][0]<<endl;
	}
	return 0;
}
