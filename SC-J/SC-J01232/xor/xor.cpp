#include<bits/stdc++.h>
using namespace std;
const int maxa=1e5+10;
int a[maxa],ans[maxa],men[maxa];
int n,k,t=0,top=0;//t代表第t个区间,top代表满足条件的第top个有几个元素 
//bool book[maxa];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			men[++t]=i;
			ans[++top]=1;
		}
	}
	men[++t]=n+1;
	for(int i=1;i<=t;i++){
		int adde=0;
		for(int j=men[i-1]+1;j<=men[i]-1;i++){
			adde^=a[j];
			if(adde==k){
				ans[++top]=j-men[i-1]+1;
				for(int r=t;r>=i;r--){
					men[r+1]=men[r];
				}
				t++;
				men[i]=j;
			} 
		}
	}
	int large=0;
	for(int i=1;i<=top;i++){
		large=max(large,ans[i]);
	}
	cout<<large<<endl;
	return 0;
}