#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long qz[5005],tot;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.ans","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		qz[i]=qz[i-1]+a[i];
		if(a[i]<qz[i-1]){
			tot=tot+1;
			if(a[i]<qz[i-2])
				tot=tot+i-1;
			//else{
			for(int j=i-3;j>=1;j--){
				if(a[i]>(qz[i-1]-qz[j])){
					tot=tot+j;	
				}
						
			}
			//}
		}
	}
	cout<<tot<<'\n';
	return 0;
}