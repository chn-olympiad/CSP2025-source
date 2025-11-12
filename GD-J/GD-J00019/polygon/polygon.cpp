#include<bits/stdc++.h>
using namespace std;
int a[5002],n,sum,ma,ans;
bool a1[5002];
void x(int m,bool b){
	a1[m]=b;
	if(m==1){
		sum=0,ma=0;
	}
	if(m==n){
		int bs=0;
		sum=0,ma=0;
			for(int i=1;i<=n;i++){
				if(a1[i]==1){
					bs++;
					if(a[i]>ma){
						ma=a[i];
					}
					sum+=a[i];
				}
			}
			if(sum>ma*2 and bs>=3){
				ans++; 
			}
			return;
		}

	
	x(m+1,0);
	x(m+1,1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int an=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) {
			an++;
		}
	}
	x(1,0);
	x(1,1);
	cout<<ans; 
	

	return 0;
}


