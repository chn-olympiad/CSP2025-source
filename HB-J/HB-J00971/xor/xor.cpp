#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	for(int i=1;i<=n;i++){
        int x=0;
        for(int j=i;j<=n;j++){
            x^=a[j];
            if(x==k){
                cnt++;
            }
        }
	}
	cout<<cnt;
	return 0;
}
