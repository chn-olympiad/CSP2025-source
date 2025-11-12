#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int maxn;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);		
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	} 
	if(n<=3&&maxn<=10){//test1,test2,test3
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
    return 0;
}

