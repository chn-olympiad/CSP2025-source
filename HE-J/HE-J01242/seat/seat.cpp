#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,df;
ll ans[1001][1001];
struct node{
	ll id,num;
}a[1000001];
bool cmp(node x,node y){
	return x.num>y.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i].num);
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			df=i;
		}
	}
	int l=1,r=0,f=1;
	for(int i=1;i<=df;i++){
		if(f==1){
			r++;
			if(r==n){
				f=2;
				if(i!=df){
					i++;
					l++;
				}
			}
		}else if(f==2){
			r--;
			if(r==1){
				f=1;
				if(i!=df){
					i++;
					l++;
				}
			}
		}
	}
	printf("%d%s%d",l," ",r);



	return 0;
	fclose(stdin);
	fclose(stdout);
}

