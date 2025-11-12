#include<bits/stdc++.h>
using namespace std;
bool v[1000000];
int a[1000000],mx,n,m,j=1,d=3,z=0;
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	while(j<=n){
		int cnt=0;
		for(int i=1;i<n;i++){
			cnt+=a[i];
		}
		if(cnt>a[d]*2){
			z++;
			d++;
			v[j]=1;
			j++;
		}else{
			d++;
			j--;
			v[j]=0;
		}
	}
	cout<<z+3;
	return 0;
} 
