#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a,b,h,c[N],w;
int s[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int k;
	cin>>a>>k;
	for(int i=0;i<a;i++){
		cin>>s[i];
	}
	for(int i=0;i<a;i++){
		for(int j=i+1;j<a;j++){
			int q+=a[j],z=a[j];
			if((q|a[j])==a[j+1]){
				c[h]=j;
				h+=1;
			}
		}
	}
	sort(c,c+a);
	cout<<c[a-1];
	return 0;
}