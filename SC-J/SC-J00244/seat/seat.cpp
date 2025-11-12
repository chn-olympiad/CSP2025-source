#include<bits/stdc++.h>
using namespace std;
bool cmp(int b,int c){
	return b>c;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int seat=n*m;
	int a[10010];
	for(int i=1;i<=seat;i++){
		cin>>a[i];
	}
	int a1=a[1];
	sort(a+1,a+seat+1,cmp);
	int n1=1,m1=1;
	for(int i=1;i<seat;i++){
		if(a[i]==a1){
			cout<<m1<<' '<<n1;
			break;
		}
		if(m1%2==1){
			if(n1==n){
				m1++;
			}else{
				n1++;
			}	
		}else{
			if(n1==1){
				m1++;
			}else{
				n1--;
			}
		}
	}
	return 0;
}