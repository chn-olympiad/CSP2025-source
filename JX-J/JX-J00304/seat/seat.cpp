#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int grade=a[1];
	sort(a+1,a+n*m+1,cmp);
	int pos=-1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==grade){
			pos=i;
		}
	}
	assert(pos!=-1);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(i&1){
			for(int j=1;j<=m;j++){
				cnt++;
				if(cnt==pos){
					cout<<i<<" "<<j<<"\n";
					return 0;
				}
			}
		}else{
			for(int j=m;j>=1;j--){
				cnt++;
				if(cnt==pos){
					cout<<i<<" "<<j<<"\n";
					return 0;
				}
			}
		}
		
	}
}
/*
no Chinese
*/
