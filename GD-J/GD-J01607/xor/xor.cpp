#include<bits/stdc++.h>
using namespace std;
int a[500000];
int n,k;
void f1(){
	
	int ans=0;
	if(!k){
		for(int i=0;i<n;i++){
			if(a[i]==0){
				ans++;
			
				continue;
			}
			else{
				for(int j=i+1;j<n;j++){
					if(j-i>=3){
						ans+=2;
	
						i=j;
						break;
						
					}
					if(a[j]==1){
						ans++;
						i=j; 
						break;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	else{
		for(int i=0;i<n;i++){
			if(a[i]==1){
				ans++;
			} 
		} 
		cout<<ans<<'\n';
	}
}
void f2(){
	int ans=0;
	for(int i=0;i<n;i++){
		if(a[i]==k){
			ans++;
			continue;
		}
		int num=a[i];
		for(int j=i+1;j<n;j++){
			num=num^a[j];
			if(num==k){
				i=j;
				ans++;
				break;
			}
		}
	}
	cout<<ans<<'\n';
}
int main() {
	freopen("xor.in.txt","r",stdin);
	freopen("xor.out.txt","w",stdout);
	cin>>n>>k;
	int num1=0;
	bool isorno=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1){
			num1++;
		}
		else if(!a[i]){
			isorno=1;
		}
	}
	if(k<=1&&!isorno){
		f1();
		return 0;
	}
	if(num1==n&&k==0){
		cout<<n/2<<'\n';
		return 0;
	}
	f2();
	
	return 0;	
}
