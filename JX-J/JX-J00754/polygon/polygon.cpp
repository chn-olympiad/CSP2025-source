#include<bits/stdc++.h>
using namespace std;
int a[1001],b[1001];
int ans;
bool cmp(int a,int b){
	return a>b;
}
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n;
cin>>n;
int cnt=0;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
}
sort(1+a,1+a+n,cmp);
if(n<=3){
	for(int i=1;i<=n;i++)
	cnt+=a[i];
	if(cnt>=2*a[1]){
		cout<<1;
		return 0;
		}
}
if(a[1]==1){
	int y=1,x=1;
	int cnt=0;
	for(int i=n;i>=1;i--){
		cnt++;
		int op=0;
		y*=i;
		for(int j=1;j<=n;j++){
			op++;
			if(i-j>2&&op==cnt){
			x*=j;
			ans+=y/x;
			}
		}
	}
}
cout<<ans;
return 0;
}
 
