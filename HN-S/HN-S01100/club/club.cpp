#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
#define ll long long 
ll n,a[N],ans,sum,x,y,z,b[4];
int main(){
	freopen("club1.in","r",stdin);
	int jilji;
	cin>>jilji;
	while(jilji--)
	{
		cin>>n;
		ans=n/2;
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>x>>y>>z;
			if(x>y&&x>z){
				a[i]=x;
				b[1]++;
			}
			if(y>x&&y>x){
				a[i]=y;
				b[2]++;
			}
			if(z>x&&z>y){
				a[i]=z;
				b[3]++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			sum+=a[i];
		}
		cout<<sum<<endl;
	}
	freopen("club.out","w",stdout);
	return 0;
}
//Ren5Jie4Di4Ling5%
