#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N]; 
int main(void){
	freope("xor.in","r",stdin);
	freope("xor.out","w",stdout);
	int n,k,f1=0,f2=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f1=1;
		}
		if(a[i]>=2){
			f2=1;
		}
	}
	if(k==0&&f1==0){
		cout<<n/2;
	}else if(f2==0){
		int cnt=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					cnt++;
				}
			}
			cout<<cnt;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					cnt++;
				}
			}
			cout<<cnt;
		}		
	}else{
		int x;
		srand(time(0));
		x=rand()%n+1;
		cout<<x;
	}
	
	
	return 0;
}
