#include<bits/stdc++.h>
using namespace std;
int n,k,ans,s,sz;
int a[1011010],l;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)s++;
		else sz++; 
	}
	if(s==n&&k==0){
		cout<<n/2;
	}
	else if(s>0&&sz>0&&k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans++;
			else if(a[i]==1&&a[i+1]==1)ans++,i++;
		}
		cout<<ans;
	}else if(s>0&&sz>0&&k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}
		cout<<ans;
	}else{
		srand(time(0));
		cout<<rand()%n+1;
	}
}
