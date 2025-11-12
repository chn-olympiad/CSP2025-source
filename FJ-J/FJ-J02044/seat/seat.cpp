#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],l,p=1,q=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			l=a[i];
		}
	}if(n==1&&m==1){
		cout<<a[1];
		return 0;
	}sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==l){
			cout<<q<<" "<<p;
			break;
		}if(p==n&&q%2==1||p==1&&q%2==0||n==1){
			q++;
		}else if(m==1){
			p++;
		}else if(q%2==1){
			p++;
		}else{
			p--;
		}
	}
	return 0;
}
