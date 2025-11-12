#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int b[N],c=0;
char a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;a[i];i++){
		if(a[i]>='0' && a[i]<='9'){
			b[c]=a[i]-'0';
			c++;
			int d=c;
			while(d--){
				if(b[d]>b[d-1] && d>=1){
				int n=b[d-1];
				b[d-1]=b[d];
				b[d]=n;
				}
			}
		}
	}
	for(int i=0;i<c;i++){
		cout<<b[i];
	}
	return 0;
}
