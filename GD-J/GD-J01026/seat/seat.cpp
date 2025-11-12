#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1005],placex=1,placey=1,flag,num=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	} 
	int t=n*m;
	flag=a[1];
	sort(a+1,a+t+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==flag){
			flag=n*m+1-i;
			break;
		}
	}
	while(1){
		//cout<<num<<endl;
		if(num==flag){
			cout<<placex<<" "<<placey;
			break;
		}
		if((placey==1&&placex%2==0)||(placey==n&&placex%2!=0)){
			placex++;
			num++;
		}
		if(num==flag){
			cout<<placex<<" "<<placey;
			return 0;
		}
		if(placex%2!=0){
			placey++;
		}
		else{
			placey--;
		}
		num++;
	}
	return 0;
}
