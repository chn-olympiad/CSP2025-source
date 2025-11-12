#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct sd{
	ll num;
	ll down;
}a[300010][5];
bool cmp(sd aa,sd b){
	return aa.num>b.num;
}
bool cmp2(ll aa,ll b){
	return aa>b;
}
ll t;
ll n,cnt,lk_1[100010],lk_2[100010],lk_3[100010];
int main(){
	//ÒÑ±£´æ 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(ll _=1;_<=t;_++){
		cnt=0;
		cin>>n;
		ll ma=n/2;
		for(ll i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
			cin>>a[i][j].num;
			a[i][j].down=j;}
		}
		for(ll i=1;i<=n;i++) sort(&a[i][1],&a[i][4],cmp);
		for(ll i=1;i<=n;i++){
			if(a[i][1].down==1){
				lk_1[i]=a[i][1].num;
			}
			else if(a[i][1].down==2){
				lk_2[i]=a[i][1].num;
			}
			else if(a[i][1].down==3){
				lk_3[i]=a[i][1].num;
			}
		}
		sort(&lk_1[1],&lk_1[n+1],cmp2);
		sort(&lk_2[1],&lk_2[n+1],cmp2);
		sort(&lk_3[1],&lk_3[n+1],cmp2);
		//for(ll i=1;i<=n;i++) cout<<lk_1[i]<<" ";
		for(ll i=1;i<=ma;i++){
			cnt+=lk_1[i]+lk_2[i]+lk_3[i];
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
