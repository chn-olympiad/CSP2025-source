#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool comp(int x,int y){
	return x<y;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n;
	cin>>n;
	ll a[5005];
	ll b[5005];
	bool qwe=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			qwe=1;
		}
	}
	if(qwe==0&&n==3){
		cout<<1;
		return 0;
	}
	if(qwe==0&&n!=3){
		int x=n-2;
		int poi=0;
		for(int i=x;i>=1;i--){
			poi+=i;
		}
		cout<<poi;
		return 0;
	}
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	sort(a+1,a+1+n,comp);
	ll num=0,ans=0,l=2,y=1;
	int x=n-2;
	while(x--){
		//for(int i=1;i<n;i++){
			for(int j=l;j<n;j++){
				ans=b[y];
				ans+=a[j];
				for(int k=j+1;k<=n;k++){
					if(a[k]<ans) num++;
				}
			}
		//}
		l++;
		y++;
	}
	cout<<num;
	return 0;
}
