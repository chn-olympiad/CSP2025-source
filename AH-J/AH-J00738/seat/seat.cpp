#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int len=n*m;
    for(int i=1;i<=len;i++){
		cin>>a[i];
	}
	int s=a[1];
	sort(a+1,a+len+1,cmp);
	int t=0;
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			t++;
			if(a[t]==s){
				if(j%2==1){
					cout<<j<<" "<<i;
				}else{
					cout<<j<<" "<<n+1-i;
				}
				return 0;
			}
		}
	}
    return 0;
}
