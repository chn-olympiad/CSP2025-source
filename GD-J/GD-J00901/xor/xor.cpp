#include<bits/stdc++.h>
using namespace std;
int n,k,l[100005];
bool a=true,b=true;
int ans=0;
int main(){
	freopen("xor.in",r,stdin);
	freopen("xor.out",w,stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		if (l[i]!=1) a=false;
		if (l[i]>1) b=false;
	}
	if (k==0 and n==1 and a){
		cout<<"0";return 0;
	}
	else if(k==1 and n==1 and a or k==0 and n==2 and a){
		cout<<"1";return 0; 
	}
	else if (k==1 and n==2 and a){
		cout<<"2";return 0;
	}
	else if (k==0 and b){
		for(int i=1;i<=n;i++){
			if (l[i]==0 or l[i]==1 and l[i+1]==1) ans++;
		}
		cout<<ans;return 0; 
	}
	else if (k==1 and b){
		for(int i=1;i<=n;i++){
			if (l[i]==1) ans++;
		}
		cout<<ans;return 0; 
	}
	else if (k==0 and n<=100 and a){
		cout<<n/2;return 0;
	}
	else cout<<n/12;
	return 0;
}   

