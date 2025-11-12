#include<bits/stdc++.h>
using namespace std;
bool dbx(int a[],int len,int st){
	int cnt=0,mx=INT_MIN;
	for(int i=0;i<len;i++){
		cnt+=a[st+i];
		mx=max(mx,a[st+i]);
		cout<<st+i<<' ';
	}
	cout<<endl;
	if(2*mx<cnt){
		return 1;
	}
	else return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n=0,ans=0,a[5050]={};cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-2;i++){
		for(int j=3;j<n-i+1;j++){
			bool f=dbx(a,j,i);
			if(f){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
