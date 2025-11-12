#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,k,a[N],cnt; 

bool check(int l,int r){
	if(l>r){
		if(a[l]==k) return 1;
		return 0;
	}
	int res=a[l];
	for(int i=l+1;i<=r;i++){
		res^=a[i];
	}
	if(res==k) return 1;
	return 0;
}

int ans(int l,int r){
	if(l==r){
		if(a[l]==k){
			return 1;
		}
		return 0;
	}
	int cnt0=0;
	for(int i=l;i<=r;){
			for(int j=i+1;j<=r;j++){
				if(check(i,j)){
					cnt0++;
					i=j+1;
//					cout<<0<<" "<<i<<" "<<j<<endl;
				}
			}
			i++;
	}
		
	int cnt1=0;
	for(int i=r;i>=l;){
		for(int j=i-1;j>=1;j--){
			if(check(j,i)){
				cnt1++;
				i=j-1;
//				cout<<1<<" "<<i<<" "<<j<<endl;
			}
		}
		i--;
	}
	return max(cnt0,cnt1);
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=1;i<n;){
			if(a[i]==a[i+1]){
				i+=2;
				cnt++;
			}else{
				i++;
			}
		}
	}else if(k==1){
		for(int i=1;i<n;){
			if(a[i]!=a[i+1]){
				i+=2;
				cnt++;
			}else{
				i++;
			}
		}
	}else{
		int l=1;
		for(int i=1;i<=n;i++){
			if(a[i]==k){
//				cout<<9<<endl;
				cnt++;
				cnt+=ans(l,i-1);
//				cout<<ans(l,i-1)<<endl;
				l=i+1;
			}
		}
		cnt+=ans(l,n);
	}
	
	cout<<cnt;

	return 0;
}
/*
4 2
2 1 0 3
rp++++++++++++++++
4 3
2 1 0 3
*/