#include<iostream>
#include<algorithm>
using namespace std;
int a[500002],sum;
bool flag[500002]={true};
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    if(k==0){
		cout<<n/2;
		return 0;
	}
    for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int l=1;l<=n;l++){
		int r=l;
		bool f=true;
		int lef=min(l,r),rig=max(l,r);
		int temp=lef;
		for(int i=lef+1;i<=rig;i++)
			temp=temp^i;
		if(temp==k)
			for(int i=lef;i<=rig;i++)
				if(flag[i]==false){
					f=false;
					break;
				}
		if(f==true){
			for(int i=lef;i<=rig;i++)
				flag[i]=false;
			sum++;
		}
		r++;
	}
	cout<<sum-1;
    return 0;
}
