#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],a1,p;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			p++;
			cin>>a[p];			
			if(p==1)
				a1=a[p];
		}
	}
	sort(a+1,a+p+1,cmp);
	for(int i=1;i<=p;i++){
		if(a[i]==a1){
			int ii=(i+n)/n;
			i%=n;	i++;
			if(ii%2==1)
				cout<<n-i<<" ";
			else
				cout<<i<<" ";
			cout<<ii;
			return 0; 
		}
	}
	return 0;
} 
