#include<bits/stdc++.h>
using namespace std;
int m,n,a,c,cnt;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c;
		if(c!=0){
			cnt++;
		}
	}int sum=1,summ=1,sum3=1,m1=m,k=cnt;
	while(cnt>0){
		sum*=cnt;
		cnt--;
	}while(m1>0){
		summ*=m1;
		m1--;
	}k-=m;
	while(k>0){
		sum3*=m1;
		k--;
	}cout<<sum/(summ*sum3)%998244353;
	return 0;
}
//998244353
