#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n;
int a[500010],qj[2000100];
long long k,ans;
int yy(int x,int y)
{
	if(x!=y) return 1;
	else return 0;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<n;
	}
	else{
		int a1,b1,res=1;
		ans=n;
		for(int i=1;i<=2;i++){
			for(int j=i;j<=n;j++){
				a1=a[i]-(a[i]>>1);
				b1=a[j]-(a[j]>>1);
				res=yy(a1,b1)*2;
				if(res==k) ans++;
			} 
		}
		cout<<ans;
	}
	return 0;
}
