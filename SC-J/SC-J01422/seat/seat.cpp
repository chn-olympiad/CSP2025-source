#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[1500];
bool cmp(int h,int g){
	return h>g;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+2,a+n*m+1,cmp);
	int ansi=1,ansj=1;
	if(a[1]>a[2]){
		cout<<"1 1";
		return 0;
	}
	for(int i=2;i<=n*m;i++){
		if(ansj%2==1){
			ansi++;
			if(ansi>n){
				ansi=n;
				ansj++;
			}
		}else{
			ansi--;
			if(ansi<1){
				ansi=1;
				ansj++;
			}
		}
		if(a[1]<a[i]&&a[1]>a[i+1]){
			cout<<ansj<<" "<<ansi;
			return 0;
		}
	}
	cout<<n<<" "<<m;
	return 0;
} 