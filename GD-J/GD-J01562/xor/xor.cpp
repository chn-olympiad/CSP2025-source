#include<bits/stdc++.h>
using namespace std;

int main(){	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[1000111],cnt=0;
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	if(k==0){
		cout<<n<<endl;;
		return 0;
	}
	if(k==1){
		for(int i=0;i<n;i++){
			if(a[i]==a[i+1]&&a[i+1]==a[i+2]&&a[i+2]==1){
				cnt++;
				i+=2;
			}
			if(a[i]!=a[i+1]) {
				cnt++;
				//i++;
			}
		}
		cout<<cnt;
		return 0;
	}
}

