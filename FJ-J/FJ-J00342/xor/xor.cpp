#include<bits/stdc++.h>
using namespace std;

struct Node{
	long long l,r;
}; 

long long n,k;
long long size_ans;
long long arr[500005];
Node ans[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int num=arr[l];
			for(int k=l+1;k<=r;k++){
				num=num^arr[k];
			}
			if(num==k){
				bool flag=false;
				for(int i=1;i<=size_ans;i++){
					int x=ans[i].l;
					int y=ans[i].r;
					if((l<x&&r<y)||(l>x&&r<y)||(l<x&&r>y)||(l>x&&r>y)){
						flag=true;
						break;
					}
				} 
				if(!flag){
					size_ans++;
					ans[size_ans].l=l;
					ans[size_ans].r=r;
				}
			}
		}
	}
	cout<<size_ans;
	return 0;
} 
