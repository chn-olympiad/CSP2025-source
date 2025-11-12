#include<bits/stdc++.h>
#define N 100010
#define M 6010
#define ll long long
using namespace std;
int n,m;
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	} 
	int tot=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==tot){
			int lie=0;
			if(i%n==0){
				lie=i/n;
			}
			else{
				lie=i/n+1;
			}
			int pai=i-(lie-1)*n;
			if(lie%2==0){
				cout<<lie<<" "<<n-pai+1;
			}
			else{
				cout<<lie<<" "<<pai;
			}
			return 0;
		}
	}
	return 0;
} 
/*
9:05
Ãë³àt2
ÎÒÒª´òÖàß÷ß÷ß÷ 
*/
