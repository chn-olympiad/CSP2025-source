#include<bits/stdc++.h>
using namespace std;
//#define int long long
int a[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			s=1;
		}
	}
	if(k==0&&s==0){
		cout<<n/2;
	}else if(k==0&&s==1){
		s=0;
		int t=0;
		for(int i=1;i<=n;i++){
			if(t==0&&a[i]==1){
				t=1;
			}else if(t==1&&a[i]==1){
				t=0;
				s++;
			}
		}
		cout<<s;
	}
	if(k==1){
		s=0;
		int t=0;
		for(int i=1;i<=n;i++){
			if(t==0&&a[i]==1){
				t=1;
			}else if(t==1&&a[i]==0){
				t=0;
				s++;
			}
		}
		cout<<s;
	}
	return 0;
}