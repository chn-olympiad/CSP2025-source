#include<bits/stdc++.h>
using namespace std;
int a[500],x[500],y[500],n,m,k,num,temp,ans;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	temp=a[1];
	for(int j=1;j<=m;j++){
		k++;
		if(j%2==1){
			for(int i=1;i<=n;i++){
				num++;
				x[num]=k;
				y[num]=i;
			}
			continue;
		}else
		if(j%2==0){
			for(int i=n;i>=1;i--){
				num++;
				x[num]=k;
				y[num]=i;
			}
			continue;
		}
	}
	sort(a+1,a+(n*m)+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==temp){
			ans=n*m-i+1;
			break;
		}
	}
	cout<<x[ans]<<' '<<y[ans];
	return 0;
}

