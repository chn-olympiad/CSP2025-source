#include<bits/stdc++.h> 
using namespace std;
int a[500010];
long long qj=0;
long long n,k;
bool hq(long long maxbs,long long l,long long r){
	int yhh=0;
	qj++;
	if(qj>=maxbs){
		for(int i=l;i<=r;i++){
			yhh=yhh^a[i];
		}
		qj--;
		return (yhh==k);
	}
	if(l>=r) {
		qj--;
		return (a[l]==k);
	}
	for(int i=l;i<r;i++){
		if(hq(maxbs,l,i)&&hq(maxbs,i+1,r)) return 1;//不是我真的是服了
	}
	qj--;
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}         
	for(int i=n;i>=1;i--){
		qj=0;
		if(hq(i,0,n-1)){
			cout<<i;
			return 0;
		}
	}    
	cout<<0;
	return 0;
}
//#Shang4Shan3Ruo6Shui4


