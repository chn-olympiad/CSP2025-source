#include<bits/stdc++.h>
using namespace std;
struct hhh
{
	int a;
	int b;
}a[1005];
bool cmp(hhh a,hhh b){
	return a.a>b.a;
}
int ans,n;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k = n*m;
	for(int i = 1;i<=k;i++){
		cin>>a[i].a;
		if(i==1){
			a[i].b = 1;
		}
	}
	sort(a+1,a+k+1,cmp);
	for(int i =1;i<=k;i++){
		a[i].a = i;
		if(a[i].b == 1){
			ans=i;
		}
	}
	int i = ans/m;
	if(ans%m!=0){
		i++;
	}
	if(ans==1){
		cout<<1<<" "<<1;
		return 0;
	}
	else if(ans==k){
		if(i%2==0){
			cout<<n<<1;
		}
		else{
			cout<<n<<m;	
		}	
	}	
	else if(i%2==0){
		cout<<i<<" "<<m-ans%m+1; 
	}
	else{
		cout<<i<<" ";
		if(ans%m==0){
			cout<<m;
		}
		else{
			cout<<ans%m;
		} 
	}
}
