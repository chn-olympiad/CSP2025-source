#include<bits/stdc++.h> 
using namespace std;
int n,m,ctt=0,cnt=1;
int a[10100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ctt=a[1];
	for(int i=2;i<=n*m;i++){
		if(a[i]>ctt){
			cnt++;
		}
	}
	if(cnt%n==0){
		cout<<cnt/n<<" ";
		if(cnt/n%2!=0){
			cout<<n;
		}
		else{
			cout<<"1";
		}
	}
	else{
		cout<<cnt/n+1<<" ";
		if((cnt/n+1)%2!=0){
			cout<<cnt%n;
		}
		else{
			cout<<n-cnt%n+1;
		} 
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
