#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
long long b[1000001];
long long maxx1=0;
long long n;
long long cheng[1000001]; 
long long o;
long long ooo=0;
void ee(int t,int g,int he){
	if(t>g){
		long long maxx=0;
		for(int i=1;i<t;i++){
			maxx=max(maxx,cheng[a[i]]);
			//cout<<cheng[a[i]]<<' ';
		}//cout<<endl;
		//cout<<maxx<<' '<<he<<endl;
		if(maxx*2<he)o++;
		o%=998244353; 
		return; 
	}
	else{
		for(int i=a[t-1]+1;i<=n;i++){
				a[t]=i;
				b[i]=1;
			ee(t+1,g,he+cheng[a[t]]);	
			}
		
		}
	}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cheng[i];
		maxx1=max(maxx1,cheng[i]);
	}
	if(maxx1==1){
		for(int i=3;i<=n;i++){
			long long ji1=1;
			for(int j=1;j<=i;j++)ji1*=j;
			long long ji=1;
			for(int j=n;j>n-i;j--){
				ji*=j;
			} 
			ji/=ji1;
			ooo+=ji;
			ooo%=998244353;
		}
		cout<<ooo;
	}
	else{
	
	sort(cheng+1,cheng+1+n);
	for(int i=3;i<=n;i++){//o=0;
	ee(1,i,0); 
	} 
      cout<<o%998244353;}
	return 0; 
}
