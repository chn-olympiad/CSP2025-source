#include<bits/stdc++.h>
using namespace std;
#define N 101
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=0;i<10;i++){
		a[i]=n%10;
		n=n/10;
	}
	int cut=0;
	for(int i=0;i<10;i++){
		int cnt=0;
		for(int j=0;j<10;j++){
			if(a[j]>cnt){
			cnt=a[j];
			}
		}
		if(cnt!=0){
		cout<<cnt;
		cut++;
		}
		for(int j=0;j<10;j++){
			if(a[j]==cnt){
			a[j]=0;
			break;
			}
		}
	}
	int e;
	e=10-cut;
	for(int k=0;k<e;k++){
		cout<<'0';
	}
	return 0;
}
