#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int st[N],l[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	int count=0;
	if(n==0){
		cout<<0;
		return 0;
	}
	if(k==0){
		bool flag=true;
		for(int i=1;i<n;i++){
			if(l[i]!=l[i+1]){
				flag=false;
			}
		}
		if(flag){
			cout<<n/2;
		}
		else{
			for(int i=1;i<=n;i++){
				if(l[i]==0){
					count++;
				}
				if(i<n && l[i]==1 && l[i+1]==1 && st[i]==0 && st[i+1]==0){
					count+=1;
					st[i]=1;
					st[i+1]=1;
				}
			}
			cout<<count;
		}
		return 0;
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(
			l[i]==1){
				count++;
			}
		}
		cout<<count;
		return 0;
	}
}
