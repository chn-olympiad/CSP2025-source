#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]; 
	}
	if(k==0){
		int t=0,p=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				t++;
			}else if(a[i]==1){
				p++;
			}
		}
		int cnt=t;
		for(int i=1;i<=n;i++){
			if(b[i]==1&&b[i+1]==1){
				cnt++;
				b[i]=0;b[i+1]=0;
			}
		}
		cout<<cnt<<endl;
	}else if(k==1){
		int t=0,p=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				t++;
			}else if(a[i]==1){
				p++;
			}
		}
		int cnt=p;
		cout<<cnt<<endl;
	}
	return 0;
}