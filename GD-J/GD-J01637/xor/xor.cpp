#include<bits/stdc++.h>
using namespace std;

int n,k,ans=0;
int a[500005];
bool used[500005];

void reset(int point,int next){
	for(int i=point;i<=next;i++){
		used[i]=false;
	}
}

int g(int l,int r){
	int sum=0,h;
	for(int i=l;i<=r;i++){
		if(used[i]){
			sum=(sum^a[i]);
		}else{
			if(i==l or i==l+1 or i-h<=2){
				h=i;
				sum=0;
				continue;
			}else if(i<r){
				if(sum==k){
					ans++;
					sum=0;
				}
			}
		}
	}
	return sum;
}

void f(int po,int ne){
	int mid=(po+ne)/2;
	if(po<ne){
		f(po,mid);
		f(mid+1,ne);
	}
	int y=g(po,ne);
	if(y==k){
		ans++;
		reset(po,ne);
	}
}

int main(){
	freopen("xor4.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(used,true,sizeof(used));
	f(1,n);
	cout<<ans;
	
	return 0;
} 
