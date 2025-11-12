#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N],k,t[3]; 
bool f=0,flag=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.ans","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) 
			f=1;
		if(a[i]!=0&&a[i]!=1)
			flag=1;
		if(flag==0)
			t[a[i]]++;
	}	
	if(k==0&&f==0){
		cout<<n/2<<'\n';
		return 0;
	}
	if(flag==0){
		if(k==1){
			cout<<t[1]<<'\n';
			return 0;
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i+1]==1){
					t[0]++;
					a[i+1]=0;
				}
			}
			cout<<t[0]<<'\n';
			return 0;
		}
	} 
	return 0;
}