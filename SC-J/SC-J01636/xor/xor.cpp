#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,t1=0,t2=0,s1=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			t1=1;
			if(a[i]!=0){
				t2=1;
			}
		}else{
			s1++;
		}
	}
	if(t1==0&&k==0){
		cout<<n/2;
	}else if(t2==0&&k<=1){
		if(k==1){
			cout<<s1;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i-1]==1){
					s1--;
					a[i]=0;
				}
			}
			cout<<n-s1;
		}
	}
	return 0; 
} 