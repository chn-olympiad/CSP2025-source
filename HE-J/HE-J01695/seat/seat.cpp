#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","w",stdout);
	int b,c,sum,n,m;
	cin>>b>>c;
	int a[b][c];
	for(int i=0;i<b;i++){
		for(int j=0;j<c;j++){
			cin>>a[i][j] ;
		}
	}
	int st=a[0][0];
	for(int i=0;i<b;i++){
		for(int j=1;j<c;j++){
			if(a[i][j]==st){
				sum++;
			}
		}
	}
	if(sum>b){
		sum=sum%b;
		if(sum%2==0){
			n=b+sum;
			m=c;
		}else if(sum%2!=0){
			n=b;
			m=c-sum;
		}
	}
	cout<<n<<" "<<m;
	return 0;
}
