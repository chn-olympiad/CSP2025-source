#include<bits/stdc++.h>
using namespace std;
int n,a[5005],bs=3;
long long ans;
long long fun(int x){
	if(x==0)return 1;
	if(x==1)return 1;
	return x*fun(x-1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    if(n==3){
        for(int i=1;i<=n-2;i++)
            for(int j=i+1;j<=n-1;j++)
                for(int k=j+1;k<=n;k++)
                    if(a[i]+a[j]>a[k])ans++;
        cout<<ans;
        return 0;
    }
    else{
		for(int i=3;i<=n;i++)ans+=fun(n)/(fun(i)*fun(n-i));
		cout<<ans;
	}
    return 0;
}
