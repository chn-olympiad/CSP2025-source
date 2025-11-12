#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int a[5005];
void d(int m,int i,int sum,int mx,string s){
	if(m==0){
		if(sum>(mx*2)){
			ans=(ans+1)%998244353;
			//cout<<sum<<" - "<<mx<<' '<<s<<endl;	
		}
		return;
	}
	if(i>=n)return;
	d(m-1,i+1,sum+a[i],max(mx,a[i]),s+char(i+'0'+1)+' ');
	d(m,i+1,sum,mx,s);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		//cout<<i<<endl<<endl;
		d(i,0,0,INT_MIN,"");
	}
	cout<<ans;
	return 0;
} 
