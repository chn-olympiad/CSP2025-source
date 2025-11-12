#include<bits/stdc++.h>
using namespace std;
string s;
int cnt,n,k,c=0,a[50000086];
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++)cin>>a[i];
for(int r=1;r<=n;r++){
	for(int l=r;l>=1;l--){
		for(int i=l;i<=r;i++){
			if(a[i]==-1){c=-1;break;}
			c^=a[i];
		}
		if(c==k){cnt++;
			//cout<<l<<" "<<r<<endl;
			for(int i=l;i<=r;i++)a[i]=-1;
			}
		c=0;
	}
}
cout<<cnt;
return 0;
}
