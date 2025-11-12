#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int num;
cin>>num;
int a[n*m];
a[0]=num;
int sum=1;
for(int i=1;i<n*m;i++){
	cin>>a[i];
	if(a[i]>num){
		sum++;
	}
}
if(sum%n==0){
	if((sum/n)%2!=0){
		cout<<sum/n<<" "<<n;
	}else{
		cout<<sum/n<<" "<<"1";
	}
}else{
	if((sum/n)%2!=0){
		cout<<sum/n+1<<" "<<n-(sum%n)+1;
	}else{
		cout<<sum/n+1<<" "<<sum%n;
	}
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
