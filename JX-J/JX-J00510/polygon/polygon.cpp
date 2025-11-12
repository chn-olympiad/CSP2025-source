#include<bits/stdc++.h>
using namespace std;
int a[5010],b[5010],c[10010],d[50100];
int main(){
	int n;
	int ans;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(a[j]<a[i]){
			int x=a[j];
			a[j]=a[i];
			a[i]=x;
            }
        }
    }
	for(int i=1;i<=n;i++){
		for(int j=50000-a[i];j>=1;j++){
			d[j+a[i]]+=c[j]+d[j];
			d[j+a[i]]=d[j+a[i]]%998244353;
			if(j>a[i])ans+=c[j]+d[j];
			ans=ans%998244353;
		}
		for(int j=1;j<=10000-a[i];j++){
			c[j+a[i]]+=b[j];
			c[j+a[i]]=c[j+a[i]]%998244353;
		}
		b[a[i]]++;
		b[a[i]]=b[a[i]]%998244353;
	}
	cout<<ans;
	return 0;
}
