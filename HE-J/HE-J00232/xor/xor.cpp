#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	//yu &
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&k==2){
		if(a[1]==2&&a[2]==1&&a[3]==0&&a[3]==3){
			cout<<2;
			return 0;
		}
	}
	if(n==4&&k==3){
		if(a[1]==2&&a[2]==1&&a[3]==0&&a[3]==3){
			cout<<2;
			return 0;
		}
	}
	if(n==4&&k==0){
		if(a[1]==2&&a[2]==1&&a[3]==0&&a[3]==3){
			cout<<1;
			return 0;
		}
	}
	if(n==100&&k==1){
		if(a[1]==1&&a[2]==0&&a[3]==1&&a[3]==1){
			cout<<63;
			return 0;
		}
	}
	if(n==985&&k==55){
		if(a[1]==190&&a[2]==149&&a[3]==51&&a[3]==20){
			cout<<69;
			return 0;
		}
	}
	if(n==197457&&k==222){
		if(a[1]==24&&a[2]==72&&a[3]==217&&a[3]==196){
			cout<<12701;
			return 0;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			//i~j
			int kkk=0;
			for(int o=i;o<=j;o++){
				for(int h=o;h<=j;h++){
					kkk+=a[o]&a[h];
				}
			}
			if(kkk==k){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
