#include<bits/stdc++.h>
using namespace std;

int n,k,sum,ans;
int f;
int a[500005];
//num[500005],book[500005];

/*bool cmp(int a,int b){
	return a>b;
}
*/

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) ans++;
		if(a[i]!=a[i-1] && i>1){
			f=1;
		}
		//max1=max(a[i],a[i-1]);
	}
	//cout<<f<<endl;
	if(f==0){
		if(a[1]==k){
			cout<<n;
			return 0;
		}
		if(k==0){
			cout<<n/2;
			return 0;
		}
		cout<<0;
		return 0;
	}
	/*
	num[1]=1;
	for(int i=2;i<=max1;i++){
		num[i]=num[i-1]*2;
	}
	sort(num+1,num+1+max1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int g=a[j];g>=1;g--){
				
			}
		}
	}
	*/
	cout<<ans;
	
	
	
	
	//#Shang4Shan3Ruo6Shui4
	
	
	return 0;
}
