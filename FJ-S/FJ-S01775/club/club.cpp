#include<bits/stdc++.h>
using namespace std;
int n,t;
struct node{
	int a1,b2,c3;
}a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t){
		int ma=0,mb=0,mc=0;
		int MAX=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].b2>>a[i].c3;
		}
		for(int i=1;i<=n;i++){
			int m=max(a[i].a1,max(a[i].b2,a[i].c3));
			if(m==a[i].a1){
				if(ma<n/2){
					ma++;
				}else m=max(a[i].b2,a[i].c3);
			}if(m==a[i].b2){
				if(mb<n/2){
					mb++;
				}else m=a[i].c3;
			}if(m==a[i].c3){
				mc++;
			}
			MAX+=m;
		}
		cout<<MAX<<endl;
		t--;
	}
	
	
	return 0;
}
