#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int p=0;
	int x=0;
	int oi=0,oj=0;
	for(int i=1;i<=n;i++){
		p=a[i];
		if(p==k){
			if(i>oj and i>oi){
				x++;
				oi=i;
				oj=i;
				continue;
			}
			if(i<oj and i<oi){
				x++;
				oi=i;
				oj=i;
				continue;
			}
		}
		for(int j=i+1;j<=n;j++){
			p=p^a[j];
			if(p==k){
				if(i>oj and j>oj){
				x++;
				oi=i;
				oj=j;
				continue;
				}
				if(i<oi and j<oi){
				x++;
				oi=i;
				oj=j;
				continue;
				}
			}
		}
	}
	cout<<x;
	return 0;
}
