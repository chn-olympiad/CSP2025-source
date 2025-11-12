#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
int a[maxn][maxn];
int cj[maxn+200];
bool cmp(int a, int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++){
		cin>>cj[i];
	}
	int len = n*m;
	int a1=cj[1];
	double stunum;
	sort(cj+1,cj+len+1,cmp);
	for(int i=1; i<=len; i++){
		if(cj[i]==a1){
			stunum=i;
			break;
		}
	}
	int y = ceil(stunum/n);
	int ys=(int)stunum%n;
	if(ys==0){
		if(y%2==0){
			cout<<y<<" "<<1;
		}else{
			cout<<y<<" "<<n;
		}
	}
	else if(y%2==0){
		int x=n-ys+1;
		cout<<y<<" "<<x;
	}else{
		cout<<y<<" "<<ys;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
