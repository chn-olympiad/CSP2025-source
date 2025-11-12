#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
void chore(){
	cout<<n/2;
	return ;
}
void solve(){
	int s=0;
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1)s++;
		}
		cout<<s;
	}else{
		for(int i=1;i<=n;i++){
			int ss=0;
			while(a[i]==1){
				ss++,i++;
			}
			s+=ss/2;
			if(a[i]==0) s++;
		}
		cout<<s;
	}
	return ;
}
void Free(){
	int su=a[1],nu=0;
	for(int i=2;i<=n;i++){
		if(su==k)nu++,su=a[i];
		else su=(su^a[i]);
	}
	if(su==k)nu++;
	cout<<nu;
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int fa=1,fb=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)fa=0;
		if(a[i]>1)fb=0;
	} 
	if(fa==1){
		chore();
	}else if(fb==1){
		solve();
	}else{
		Free();
	}
	return 0;
}
