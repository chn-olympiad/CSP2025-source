#include<iostream>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,num=0,ans=0;
	cin>>n;
	int a[n],big;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		for(int j=0;j<i;j++){
			num=0;
			for(int k=0;k<n;k++){
				num+=a[k]; 
				if(big<a[k])big=a[k];
			}
			if(big*2<num)ans++;
		}
	}
	cout<<ans;
    return 0;
}

