#include<algorithm>
#include<iostream> 
using namespace std;
int n,m;
int all[105],r,bian;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>all[i];
		if(i==1){
			r=all[i];
		}
	}
	sort(all+1,all+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(all[i]==r){
			bian=i;
			break;
		}
	}
	int lie=ceil(bian*1.0/n);
	cout<<lie<<' ';
	if(lie%2==1){//ÆæÊýÁÐ 
		cout<<bian-(lie-1)*n;
	}else{
		cout<<n-(bian-(lie-1)*n)+1;
	}
	return 0;
}
