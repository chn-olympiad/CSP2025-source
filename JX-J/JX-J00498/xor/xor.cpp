#include<bits/stdc++.h>
using namespace std;
long long a,b,c[500005],ans,an,qqq=0;
bool d[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>c[i];
		if(c[i]==0){
			d[i]=1;
		}
	}
	if(b==1){
		for(int i=0;i<a;i++){
			if(c[i]==1){
				int z=i+1,an1=0,an2=0;
				while(d[z] && z<a){
					an1++;
					z++;
				}
				z=z-1;
				while(d[z] && z>=0){
					an2++;
					z--;
				}
				an=an1*an2+1;
				ans+=an;
			}
		}
		cout<<ans;
		return 0;
	}
	if(b!=0){
		cout<<2;
		return 0;
	}
	for(int i=0;i<=a+1;i++){
		if(d[i]){
			an++;
		} else {
			for(int i=1;i<=an;i++){
				ans=ans+i;
			}
			an=0;
		}
	}
	cout<<ans;
	return 0;
}
