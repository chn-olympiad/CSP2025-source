#include<bits/stdc++.h>
using namespace std;
int a[114],n,m,r,rc,rr,i,j=1,k=1,ACE[15][15];
void ans1(){
	while(k<=n){
		if(a[i]==r){
			if(k==0){
				k++,j++;
			}
			if(j>m)j--;
			cout<<j<<' '<<k;
			exit(0);
		}
		ACE[j][k]=a[i];
		i--,k++;
	}
	return ;
} 
void ans2(){
	while(k>0){
		if(a[i]==r){
			if(k>n){
				k--,j++;
			}
			if(j>m)j--;
			cout<<j<<' '<<k;
			exit(0);
		}
		ACE[j][k]=a[i];
		i--,k--;
	}
	return ;
}
int main(){
	int fcbsc=0;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int kkk=1;kkk<=n*m;kkk++) cin>>a[kkk];
	r=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==r) fcbsc=n*m-i+1;
	}
	if(n==1){
		cout<<fcbsc<<' '<<1;
		return 0;
	} 
	ACE[1][1]=a[n*m];
	i=n*m;
	for(i=n*m;i>=1;){
		if(k<=n){
			ans1();
		} else {
			k--;
			ans2();
		}
		j++;
	}
	return 0;
}