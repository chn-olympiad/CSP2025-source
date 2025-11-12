#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[1000],tmp;
bool cmp(int a,int b){
	return a>b;
}
void f(int n,int id){
	int x=((id-1)/n)+1,y=(id-1)%n+1;
	cout<<x<<" ";
	if(x&1){
		cout<<y<<endl;
		return;
	}else{
		cout<<n-y+1<<endl;
		return;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)tmp=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int id=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==tmp){
			id=i;
			break;
		}
	}
	f(n,id);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

