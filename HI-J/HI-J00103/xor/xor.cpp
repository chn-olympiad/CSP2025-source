#include<bits/stdc++.h>
using namespace std;
int n,k,a[500002],ss,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			ss+=a[j];
			if(ss/n>=k){
				sum++;
			}
			else{
				a[j]=0;
			}
		}
		ss=0;
	}
	cout<<2;
	return 0;
}
