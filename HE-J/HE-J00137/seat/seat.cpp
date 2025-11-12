#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[250];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int score=a[1];
	sort(a+1,a+n*m+1);
	for (int i=n*m;i>=1;i--){
		if (a[i]==score){
			int cnt=m*n-i+1;
			int c=cnt/n;
			int mod=cnt%n;
			if (mod!=0){
				cout<<c+1<<" ";//列 
				if ((c+1)%2!=0){//奇数列 
					cout<<mod<<endl;
				}
				else {//偶数列逆序 
					cout<<n-mod+1<<endl;
				}
			}
			else if(mod==0){
				cout<<c<<" "<<n;//每列最后一个 
			}
			break;
		}
	}
	return 0;
}

