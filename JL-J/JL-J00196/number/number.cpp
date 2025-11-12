#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char c[N];
int a[N],sum,t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=N;i++){
		cin>>c[i];
		if(int(c[i])<9&&int(c[i])>0){
			a[i]=int(c[i]);
			sum++;
		}
		if(!c){
			break;
		}
	}
	for(int i=1;i<=sum;i++){
		for(int j=1;j<=sum;j++){
			if(a[j]>a[j+1]){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=a[j];
			}
		}	
	}
	for(int i=1;i<=sum;i++){
		cout<<a[i];
	}
	return 0;
}
