#include<bits/stdc++.h>
using namespace std;
int a[500005];
int c[500005];
int b[1005];
int d[500005];
bool e[500005];
int num = 0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		num+=a[i];
		c[a[i]] = i;
		d[i] = d[i-1]^a[i];
	}
	if(num==0){
		if(k==0){
			cout<<n;
		} 
		else{
			cout<<0;
		}
	}
	else if(num<=n){
		if(k==1){
			cout<<num;
		}
		else{
			cout<<0;
		}
	}
	else{
		int y = 0;
		for(int i = 1;i<=n;i++){
			for(int j = i;j<=n;j++){
				int u = d[j]^d[i-1];
				if(u==k){
					b[i] = j;
				}
			}
		}
		for(int i = 1;i<=n;i++){
			if(e[i]==false and e[b[i]]==false){
				y++;
				for(int j = i;j<=b[i];j++){
					e[j] = true;
				}
			}
		}
		cout<<y;
	}
	return 0;
}
