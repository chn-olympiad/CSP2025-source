#include<bits/stdc++.h>
using namespace std;
int a[1000];
int n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			s=i;
			break;
		}
	}
	if(s%n == 0){
		cout<<s/n<<' ';
		if((s/n)%2 == 1) cout<<n;
		else cout<<1;
	}
	else{
		cout<<(s/n)+1<<' ';
		if(((s/n)+1)%2 == 1) cout<<s%n;
		else cout<<n-(s%n)+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
