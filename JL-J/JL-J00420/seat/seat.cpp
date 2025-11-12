#include<bits/stdc++.h>
using namespace std;
#define N 1001
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=1;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int q=a[0];
	for(int i=1;i<n*m;i++){
		if(q<a[i]){
			cnt++;
		}
	}
	int w;
	if(cnt%n==0){
		w=cnt/n;
		cout<<w<<" ";
		if(w%2==0){
			cout<<'1';
		}
		if(w%2==1){
			cout<<n;
		}
	}
	if(cnt%n!=0){
		w=cnt/n+1;
		cout<<w<<" ";
		if(w%2==0){
			cout<<n-(cnt%n)+1;
		}
		if(w%2==1){
			cout<<cnt%n;
		}
	}
	return 0;
}
