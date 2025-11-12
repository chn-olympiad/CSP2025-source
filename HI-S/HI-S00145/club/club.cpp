#include<bits/stdc++.h>
using namespace std;
int t,n,ma,mb,mc,s;
struct zh{
	int a,b,c;
}a[100100];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
		ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(int o=1;o<=t;o++){
		cin>>n;
			ma=mb=mc=n/2;
		for(int j=1;j<=n;j++){
				cin>>a[j].a>>a[j].b>>a[j].c;
		}
		for(int i=1;i<=n;i++){
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c&&ma>0){
				s+=a[i].a;
				ma--;
			}
			else if(a[i].b>=a[i].c&&a[i].b>=a[i].a&&mb>0){
				s+=a[i].b;
				mb--;
			}
			else if(a[i].c>=a[i].b&&a[i].c>=a[i].a&&mc>0){
				s+=a[i].c;
				mc--;
			}
			else if(ma<=0){
				if(mb>=mc){
					s+=a[i].b;
					mb--;
				} 
				else{
					s+=a[i].c;
					mc--;
				}
				
			}
			else if(mb<=0){
				if(ma>=mc){
					s+=a[i].a;
					ma--;
				} 
				else{
					s+=a[i].c;
					mc--;
				}
				
			}
			else if(mc<=0){
				if(mb>=ma){
					s+=a[i].b;
					mb--;
				} 
				else{
					s+=a[i].a;
					ma--;
				}
				
			}
		}
cout<<s<<"\n";
s=0;
	}
	return 0;
}
