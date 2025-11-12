#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],ans[105],anst[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int c=n*m;
	for(int i=1;i<=c;i++){
		cin>>a[i];
	}
	int s=a[1];
	sort(a+1,a+c+1);
	int b=1;
	for(int i=m;i>=1;i--){
		if(i%2==0){
			for(int j=1;j<=n;j++){
				ans[a[b]]=i;
				anst[a[b]]=j;
				b++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				ans[a[b]]=i;
				anst[a[b]]=j;
				b++;
			}
		}
	}
	cout<<ans[s]<<" "<<anst[s];
	return 0;
} 
