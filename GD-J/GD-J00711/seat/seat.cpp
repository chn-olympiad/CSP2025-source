#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	int q=1,w=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			cout<<w<<" "<<q;
			return 0;
		}
		if(w%2==1){
			q++;
			if(q>n){
				w++;
				q--;
			}
		}
		else{
			q--;
			if(q<1){
				w++;
				q++;
			}
		}
	}
	return 0;
}
