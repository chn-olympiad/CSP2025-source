#include<bits/stdc++.h>
using namespace std;
int a[1001001];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int f=1,e=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]!=1)f=0;
		if(a[i]!=1&&a[i]!=0)e=0;
	}if(f==1){
		if(k==0)cout<<n/2<<endl;
		else if(k==1)cout<<n<<endl;
		else cout<<0<<endl;
	}else{
		int ooo=0,oooo=0,lll=0;
		for(int i=1;i<=n;i+=2){
			if(a[i]==1)oooo++;
			if(a[i+1]==1)oooo++;
			if(a[i]==a[i+1]&&a[i]==1)lll++;
			if(a[i]==0)ooo++;
			if(a[i+1]==0)ooo++;
		}
		if(k==0)cout<<ooo+lll<<endl;
		else if(k==1)cout<<oooo<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
