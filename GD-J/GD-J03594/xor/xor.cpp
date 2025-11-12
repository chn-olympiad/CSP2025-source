#include<bits/stdc++.h>
using namespace std;
bool flaga=true,flag[500005],jg=true;
long long n,k;
long long a[500005],ans1=0,ans2=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]!=1) flaga=false;
		if(a[i]!=0&&a[i]!=1) jg=false;
	} 
	if(k==0){
		if(flaga==true) cout<<(n/2)<<endl;
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==a[i+1]&&i+1<=n&&flag[i]==false&&flag[i+1]==false){
					ans1++;
					flag[i]=true;
					flag[i+1]=true;
				}
			}
			
			cout<<ans1<<endl;
		}
	}
	else{
		if(jg==true){
			if(k!=1) cout<<0<<endl;
			else{
				for(int i=1;i<=n;i++){
					if(a[i]!=a[i+1]&&i+1<=n&&flag[i]==false&&flag[i+1]==false){
						ans2++;
						flag[i]=true;
						flag[i+1]=true;
					}
			}
				cout<<ans2<<endl;
			}
		}
	}
	return 0;
} 
