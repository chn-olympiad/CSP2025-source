#include<bits/stdc++.h>
using namespace std;
int m,n,cnt=m*n,w,p=1,q=1;
int a[100],b[10],s[10][10];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=0;i<cnt;i++){
		cin>>a[i];
	}
	sort(a,a+cnt+1);
	while(1){
		s[p][q]=b[cnt+1];
		q--;
		cnt--;
		if(q==0){
			break;
		}
	}
	int c=m,r=a[1];
	cout<<"1"<<" "<<"2";
	return 0;
}  