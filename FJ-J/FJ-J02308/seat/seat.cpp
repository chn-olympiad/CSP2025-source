#include<bits/stdc++.h>
using namespace std;
int qwe(int a,int b){
	
		return a>b;
} 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m,k,sum=0;
	cin>>n>>m;
	int a[105];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	int h=n*m;
	sort(a+1,a+h+1,qwe);
    for(int i=1;i<=n*m;i++){
    	if(a[i]==k){
    		sum=i;
    		break;
		}
	}
	if(sum%n==0&&sum/n%2==1)cout<<sum/n<<" "<<n;
	if(sum%n==0&&sum/n%2==0)cout<<sum/n<<" "<<1;
	if(sum%n!=0&&sum/n%2==1)cout<<sum/n<<" "<<sum%n;
	if(sum%n!=0&&sum/n%2==0)cout<<sum/n<<" "<<n-(n-sum%n);
	return 0;
}
