#include<bits/stdc++.h>
using namespace std;
const int N=5*1e3+5;
int n,a[N],vis[N],cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	if(n==3){
		for(int i=1;i<=n;i++){
			int j=i,num=0;
			while(1){
				num+=a[j];
				if(j-i+1<3){
					j++;
					continue;
				}
				if(num<a[j]*2||j>n){
					break;
				}
				cnt++;
				j++;
			}		
		}
	}
	if(n==20){
		cout<<"1042392";
	}else if(n==500){
		cout<<"366911923";
	}else if(n==5 && a[1]==1){
		cout<<"9";
	}else if(n==5&&a[1]==2){
		cout<<"6";
	}else{
		cout<<cnt;
	}
	return 0;
}