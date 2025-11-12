#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5010],cnt=0;
bool f=true;
int jie(int n){
	int sum=1;
	for(int i=2;i<=n;i++){
		sum*=i;
	}
	return sum;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=false;
		}
	}
	if(!f){
		for(int i=1;i<=(1<<n)-1;i++){
			int li=i;
			int ln=n;
			int b[5010];
			memset(b,0,sizeof(b));
			while(li>0){
				b[ln]=li%2;
				ln--;
				li/=2;
			}
			int he=0,maxi=-10000;
			if(n-ln<3){
				continue;
			}
			ln++;
			for(int j=ln;j<=n;j++){
				he+=b[j]*a[j];
				if(b[j]==1){
					maxi=max(maxi,a[j]);
				}
			}
		
			if(he>(2*maxi)){
				cnt++;
				cnt%=998244353;
			}
		}
		cout<<cnt<<endl;
	}
	else{
		for(int i=3;i<=n;i++){
			cout<<cnt<<endl;
			if(i==n){
				cnt+=1;
				cnt%=998244353;
			}
			else{
				cnt+=jie(n)/jie(n-i)/jie(i);
				cnt%=998244353;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
