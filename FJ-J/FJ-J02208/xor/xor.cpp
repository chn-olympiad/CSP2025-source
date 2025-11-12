#include<iostream>
using namespace std;
int n,k;
int a[500010];
int d[500010];
int l;
int ans=0;
int fl;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			d[++l]=i;
		}
	}
	d[++l]=n+1;
	for(int i=1;i<=l;i++){
    	fl=d[i-1]+1;
		for(int j=d[i-1]+2;j<=d[i]-1;j++){
			for(int z=fl;z<j;z++){
				int sum=a[z];
				for(int w=z+1;w<=j;w++){
					sum=(sum|a[w])-(sum&a[w]);
				}
				if(sum==k){
					fl=j+1;
					ans++;
					break;
				}
			}
		}
	}
	cout<<ans+l-1<<endl;
	return 0;
}
