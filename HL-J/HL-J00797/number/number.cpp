#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10; 
char a[N];
int b[N],c[N];
int myi=-1;
int maxn=-1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s=0;
	while(cin>>a[s]){
		s++;
	}
	int sum=0;
	for(int i=0;i<s;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[sum]=a[i]-48;
			sum++;
		}
	}
	for(int j=0;j<sum;j++){
		for(int i=0;i<sum;i++){
			if(b[i]>maxn){
				maxn=b[i];
				myi=i;
			}
		}
		c[j]=maxn;
		b[myi]=-1;
		maxn=-1;
		myi=-1;
	}
	for(int i=0;i<sum;i++){
		cout<<c[i];
	}
	return 0;
}
