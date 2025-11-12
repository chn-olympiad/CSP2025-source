#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int i,j;
bool sum=true;
int cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n<=3){
		if(n<3){
			cout<<0;
			return 0;
		}
		else{
			if(a[0]+a[1]<=a[2]&&a[0]!=0&&a[1]!=0&&a[2]!=0){
				cout<<0;
				return 0;
			}
			else{
				cout<<1;
				return 0;
			}
		}
	}
	else{
		for(i=0;i<n;i++){
			if(a[i]>1){
				sum=false;
			}
		}
		if(sum==true){
			int k=2;
			while(k<n){
				for(j=k;j<n;j++){
					cnt++;
				}
				k++;
			}
			cout<<cnt;
			return 0;
		}
		else{
			cout<<114514;
		}
	}
	return 0;
}

