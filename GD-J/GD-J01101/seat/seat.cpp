#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool hzm(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int sum=a[1];
	sort(a+1,a+1+n*m,hzm);
	int x=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==sum){
			x=i;
			break;
		}
	}
	int h=1,w=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==sum){
			if(w%2==0){
				cout<<w<<" "<<h-1+n;
				break;
			}
			cout<<w<<" "<<h;
			break;
		}
		h++;
		if(h>n){
			h=1;
			w++;
		}
	}
	return 0;
}
