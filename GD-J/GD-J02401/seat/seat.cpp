#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],n,m,end;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int end=0; 
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)end=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1,now=1;
	int flg=1;
	while(1){
//		cout<<x<<' '<<y<<' '<<flg<<endl;
		if(a[now]==end){
			cout<<x<<' '<<y<<endl;
			return 0;
		}
		now++;
		if(y==m&&flg==1){
//			cout<<"!!!\n";
			x++;
			flg=0;
		}
		else if(y==1&&flg==0){
			x++;
			flg=1;
		}
		else if(flg==0){
			y--;
		}
		else{
//			cout<<flg<<endl;
			y++;
		}
	}
}
/*
#Shang4Shan3Ruo6Shui4
*/
