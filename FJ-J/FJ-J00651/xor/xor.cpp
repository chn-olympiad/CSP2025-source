#include<iostream>
using namespace std;
int n,k,l,a[500005],x=-1,c;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int r=0;r<n;r++){
		int b=0;
		for(int l=r;l>x;l--){
			b=b^a[l];
			if(b==k) x=r,c++;
		}
	}
	cout<<c<<endl;
	return 0;
}
