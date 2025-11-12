#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000];
long long i,j,f,ans,k,l,r,op,AC;
int main(){
//	freopen("D:\\number4.in","r",stdin);

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	ans=n*m;
	for(i=1;i<=ans;i++){
		cin>>a[i]; 
	}
	f=a[1];
	sort(a+1,a+1+ans);
	for(i=1;i<=ans/2;i++){
		if(i<ans-i+1)
			swap(a[i],a[ans-i+1]);
	}
//	for(i=1;i<=ans;i++){
//		cout<<a[i]<<' ';
//	}cout<<endl;
	i=1;j=1;k=1;
	while(true){
		if(a[k]==f){
			cout<<j<<' '<<i<<endl;
			return 0;
		}
		if(j%2==0){
			if(i>1){
				i--;
			}
			else{
				j++;
			}
		}
		else{
			if(i<n){
				i++;
			}
			else{
				j++;
			}
		}
		k++; 
	}
	return 0;
}
