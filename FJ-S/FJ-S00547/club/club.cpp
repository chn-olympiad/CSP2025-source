#include<bits/stdc++.h>
using namespace std;
int t,n;
struct s{
	int a,b;
}a[100005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[j].a;
				a[j].b=j;
			}
			for(int j=1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					if(a[j].a<a[z].a){
						swap(a[j],a[z]);
					}
				}	
			}
		}
		for(int i=1;i<=3;i++){
			cout<<a[i].a<<" "<<a[i].b<<endl; 
		}
	}
	return 0;
}
