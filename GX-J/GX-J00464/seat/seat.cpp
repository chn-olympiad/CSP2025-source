#include<bits/stdc++.h>
using namespace std;
int a[15][15],b[105];
int n,m,i=1,j=1;
int R=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
		cin>>b[i];
	R=b[1];
	sort(b,b+n*m,cmp);
	int cnt=0;
	for(i=1;i<=n*m;i++){
		if(b[i]==R){
			cnt=i;
			break;
		}else continue;
	}
	int cnt1=0;
	i=0;j=0;
	while(true){
		if(j%2==1){
			cnt1++;
			if(b[cnt1]==R){
				cout<<j<<" "<<i;
				break;
			}
			else{
				if(i==n)j++;
				else i++;
			}
		}else{
			cnt1++;
			if(b[cnt1]==R){
				cout<<j<<" "<<i;
				break;
			}
			else{
				if(i==1)j++;
				else i--;
			}
		}
	}
	return 0;
}
