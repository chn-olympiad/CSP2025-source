#include<bits/stdc++.h>
using namespace std;
const int N=105;
struct p{
	int poi;
	int xu;
}a[N];
bool cmp(p x,p y){
	return x.poi>y.poi;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	int p=n;
	int sum=1;
	int q=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].poi;
		a[i].xu=i;
	}
	q=a[1].poi;
	sort(a+1,a+1+n*m,cmp); 
	for(int i=1;i<=n*m;i++){
		if(a[i].poi!=q){
			sum++;
		}else{
			break;
		}
	} 
	for(int i=1;i<=m;i++){
		if(sum<=p){
			sum-=p-n;
			cout<<p/n<<" ";
			break;
		}else{
			p+=n;
		} 
	}
	if(p/n%2==0){
		cout<<m-sum+1;
	}else{
		cout<<sum;
	}

	return 0;
}