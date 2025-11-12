#include<bits/stdc++.h>
using namespace std;
int m,n,ans,sum;
int a[111]={0};
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
    }
    ans=a[1];
    sort(a+1,a+m*n+1,cmp);
    for(int i=1;i<=m*n;i++){
		if(a[i]==ans) sum=i;
    }
    int x,y;
    if(sum%n!=0) x=sum/n+1;
    else x=sum/n;
    if(sum>n){
		if(x%2==1) y=sum%n;
        else y=n+1-sum%n;
	}else y=sum;
    cout<<x<<' '<<y;
	return 0;
}
