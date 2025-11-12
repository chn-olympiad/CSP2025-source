#include<bits/stdc++.h>
using namespace std;
#define Inff 1000000
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long a[Inff],n,sum=0,place1[Inff];
		memset(place1,0,sizeof(place1));
		cin>>n;
		for(int i=1,b,c;i<=n;i++){
			cin>>a[i]>>b>>c;
		}
		for(int i=1;i<=n;i++){
			long long max=-1,place;
			if(max<a[i]){
				max=a[i];
				place=i;
			}
			if(i==n){
				sum+=max;
				place1[place]=1;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
