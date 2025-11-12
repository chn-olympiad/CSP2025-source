#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	int a[10005],sum=0,num=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]*2<sum){
			num++;
		}
	}
	cout<<num;
	return 0;
}

