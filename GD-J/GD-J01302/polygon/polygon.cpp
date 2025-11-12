#include<bits/stdc++.h>
using namespace std;
int n,a[5005],tmp[5005],tmp_l; 
long long ans;
bool can_be_a_polygon(int a[],int l){
	if(l<3)return false;
	int sum=0,maxx=-1;
	for(int i=1;i<=l;i++){
		sum+=a[i];
		maxx=max(maxx,a[i]);
	}
	if(sum>maxx*2)return true;
	else return false;
}
void move(int a[],int l,int r){
	tmp_l=1;
	for(int i=l;i<=r;i++){
		tmp[tmp_l]=a[i];
		tmp_l++;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	/*12pts*/
	if(n==3){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(can_be_a_polygon(a,3))cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			move(a,i,j);
			if(can_be_a_polygon(tmp,tmp_l))ans++;
		}
	}
	cout<<ans%998244353;
	return 0;
} 
