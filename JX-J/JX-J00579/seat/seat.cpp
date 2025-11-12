#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	//int c,r;
	int len=n*m;
	for(int i=1;i<=len;i++){
		cin>>a[i];
	}
	int R=a[1];
	sort(a,a+len+1);
	int cnt=len;
	int m1=1;
	int flag=2;
	for(int j=1;j<=m1;j++){
		//cout<<"nm"<<endl;
		if(m1<0||m1>m){
			break;
		}
		if(flag==2){
			for(int i=1;i<=n;i++){
				b[i][m1]=a[cnt];
				cnt--;
			}
			m1++;
			flag=1;
			//cout<<"fuck"<<endl;
		}
		if(flag==1){
			for(int i=n;i>=1;i--){
				b[i][m1]=a[cnt];
				cnt--;
			}
			m1++;
			flag=2;
			//cout<<"shit"<<endl;	
		}
	}
	//for(int i=1;i<=len;i++){
		//cout<<a[i]<<" ";
	//}
	//cout<<endl;
	//for(int i=1;i<=n;i++){
		//for(int j=1;j<=m;j++){	
			//cout<<b[i][j]<<" "; 
		//}
		//cout<<endl;
	//}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==R){
				cout<<j<<" "<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
}
