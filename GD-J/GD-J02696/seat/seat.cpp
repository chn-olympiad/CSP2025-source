#include<bits/stdc++.h>
using namespace std;
struct s{
	int id;
	int sor;
}a[110];
bool p(s a,s b){
	return a.sor>b.sor;
}
int n,m;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].sor;
		a[i].id=i;
	}
	sort(a+1,a+n*m,p);
	int a_s;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			a_s=i;
			break;
		}
	}
	if(a_s%n==0){
		cout<<a_s/n<<" "<<m<<endl;
	}else cout<<a_s/n+1<<" "<<a_s%n;
	return 0;
}
