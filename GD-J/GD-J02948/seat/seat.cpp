#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[100010],x,s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	for (int i=1;i<=n*m;i++){
		cin >>a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for (int i=1;i<=n*m;i++){
		if (a[i]==x){
			s=i;
			break;
		}
	}
	cout<<(s+n-1)/n<<" ";
	if ((s+n-1)/n%2==0){
		if (s%n==0){
			cout <<1;
		}else{
			cout <<n-s%n+1;
		}
	}else{
		if(s%n==0)cout <<n;
		else cout <<s%n;
	}
	return 0;
}
