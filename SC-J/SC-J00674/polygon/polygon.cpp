#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,ma;
long long cnt;
int main(){
	freopen("polygon.in","r",stdin); freopen("polygon.out","w",stdout); 
    cin>>n;
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    if(n<3) cout<<"0";
    if(n==3){
    	for(int i=1;i<=n;++i){
		cnt+=a[i];
		ma=max(a[i],ma);
     	}
    	if(cnt>ma*2) cout<<"1";
    	else cout<<"0";
	}
	sort(a+1,a+n+1);
	if(n==4){
		if(a[1]+a[2]+a[3]>a[3]*2) ans++;
		if(a[1]+a[2]+a[4]>a[4]*2) ans++;
		if(a[1]+a[3]+a[4]>a[4]*2) ans++;
		if(a[2]+a[3]+a[4]>a[4]*2) ans++;
		if(a[1]+a[2]+a[3]+a[4]>a[4]*2) ans++;
		cout<<ans;
	}
	if(n==5){
		if(a[1]+a[2]+a[3]>a[3]*2) ans++;
		if(a[1]+a[2]+a[4]>a[4]*2) ans++;
		if(a[1]+a[2]+a[5]>a[5]*2) ans++;
		if(a[2]+a[3]+a[4]>a[4]*2) ans++;
		if(a[2]+a[3]+a[5]>a[5]*2) ans++;
		if(a[2]+a[4]+a[5]>a[5]*2) ans++;
		if(a[3]+a[4]+a[5]>a[5]*2) ans++;
		if(a[1]+a[2]+a[3]+a[4]>a[4]*2) ans++;
		if(a[1]+a[2]+a[3]+a[5]>a[5]*2) ans++;
		if(a[1]+a[2]+a[4]+a[5]>a[5]*2) ans++;
		if(a[1]+a[3]+a[4]+a[5]>a[5]*2) ans++;
		if(a[2]+a[3]+a[4]+a[5]>a[5]*2) ans++;
		if(a[1]+a[2]+a[3]+a[4]*a[5]>a[5]*2) ans++;
		cout<<ans;
	}
	for(int i=1;i+2<=n;++i){
		for(int j=i+1;j+1<=n;++j){
			for(int k=j+1;k<=n;++k){
				if(a[i]+a[j]+)
			}
		}
	}
	if(n==6){
		if(a[1]+a[2]+a[3]>a[3]*2) ans++;
		if(a[1]+a[2]+a[4]>a[4]*2) ans++;
		if(a[1]+a[2]+a[5]>a[5]*2) ans++;
		if(a[1]+a[2]+a[6]>a[6]*2) ans++;
		if(a[2]+a[3]+a[4]>a[4]*2) ans++;
		if(a[2]+a[3]+a[5]>a[5]*2) ans++;
		if(a[2]+a[3]+a[6]>a[6]*2) ans++;
		if(a[2]+a[4]+a[5]>a[5]*2) ans++;
		if(a[2]+a[4]+a[6]>a[6]*2) ans++;
		if(a[3]+a[4]+a[5]>a[5]*2) ans++;
		if(a[3]+a[4]+a[6]>a[6]*2) ans++;
		if(a[4]+a[5]+a[6]>a[6]*2) ans++;
		if(a[1]+a[2]+a[3]+a[4]>a[4]*2) ans++;
		if(a[1]+a[2]+a[3]+a[5]>a[5]*2) ans++;
		if(a[1]+a[2]+a[3]+a[6]>a[6]*2) ans++;
		if(a[1]+a[2]+a[4]+a[5]>a[5]*2) ans++;
		if(a[1]+a[2]+a[5]+a[6]>a[6]*2) ans++;
		if(a[1]+a[3]+a[4]+a[5]>a[5]*2) ans++;
		if(a[1]+a[3]+a[4]+a[6]>a[6]*2) ans++;
		if(a[1]+a[4]+a[5]+a[6]>a[6]*2) ans++;
		if(a[2]+a[3]+a[4]+a[5]>a[5]*2) ans++;
		if(a[2]+a[4]+a[5]+a[6]>a[6]*2) ans++;
		if(a[3]+a[4]+a[5]+a[6]>a[6]*2) ans++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]>a[5]*2) ans++;
		if(a[1]+a[2]+a[3]+a[4]+a[6]>a[6]*2) ans++;
		if(a[2]+a[3]+a[4]+a[5]+a[6]>a[6]*2) ans++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>a[6]*2) ans++;
		cout<<ans;
		
	}
	fclose(stdin); fclose(stdout);
	return 0;
}