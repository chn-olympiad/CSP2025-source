#include<bits/stdc++.h>
using namespace std;
int n,m,ss,mark;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	ss=n*m;
	for(int i=1;i<=ss;i++){
		cin>>a[i];
	}
	mark=a[1];
	sort(a+1,a+ss+1,cmp);
	for(int i=1;i<=ss;i++){
		if(a[i]==mark){
			int x=(i+n-1)/n;
			if(x%2==1){
				i%=n;
				if(i==0){
					cout<<x<<" "<<n;
					break;
				}else{
					cout<<x<<" "<<i;
					break;
				}
			}else{
				i%=n;
				if(i==0){
					cout<<x<<" "<<1;
					break;
				}else{
					cout<<x<<" "<<n-(i-1);
					break;
				}
			}
		}
	}

	return 0;
}
