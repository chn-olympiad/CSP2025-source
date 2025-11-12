#include<bits/stdc++.h>
using namespace std;
int a[5050];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ans,idans;cin>>n>>m;
	cin>>a[1];
	ans=a[1];
	for(int i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(ans==a[i]){
			idans=i;
			break;
		}
	//m为列  n为行 
	int lie;
	if(idans%n!=0) lie=( ( (idans-idans%n) /n) +1 );
	else lie=idans/n;
	if(lie%2==1){//奇数列 
		cout<<lie<<" ";
		cout<<idans-(lie-1)*n; 
	}else{
		cout<<lie<<" ";
		cout<<n+1-(idans-(lie-1)*n);
	}
	cout<<endl;
	return 0;
}

