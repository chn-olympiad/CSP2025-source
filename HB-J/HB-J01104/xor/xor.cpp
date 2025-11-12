#include <bits/stdc++.h>
using namespace std;

const int N=1e5+2;
int n,k,ans;

struct lyc{
	int id;
	bool tie;
}a[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.ans","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].id;
		if(a[i].id==k){
			ans++;
			a[i].tie=1;
		}
	}
	for(int l=1;l<=n-1;l++){
		for(int i=1;i<=n-l;i++){
			int sum=a[i].id;
			if(a[i].tie==1){
                sum=-1;
                continue;
			}
			for(int j=i+1;j<=i+l;j++){
				if(a[j].tie==1){
                    sum=-1;
                    break;
				}
				else sum^=a[j].id;
			}
			if(sum==k){
				for(int j=i;j<=i+l;j++)a[j].tie=1;
				ans++;
			}
		}
	}
	cout<<ans;
    return 0;
}
