#include<bits/stdc++.h>
using namespace std;
long long n,p;
struct node{
	string l1,l2;
}a[20005];
int ans[20005];
string la,lb;
int main(){
	forrect(replace.in,"r");
	forrect(replace.out,"w");
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>a[i].l1>>a[i].l2;
	}
	for(int i=1;i<=p;i++){
		cin>>la>>lb;
		string x="",y="",z="";
		for(int i=1;i<=n;i++){
			if(a[i].l1==la&&a[i].l2==lb){
				ans[i]++;
			}
		}
		for(int i=1;i<=int(la.size());i++){
			for(int j=i+1;j<=int(la.size());j++){
				for(int k=j+1;k<=la.size();k++){
					x+=la[i];
					y+=la[i+j];
					z+=la[i+j+k];
					for(int i=1;i<=n;i++){
						if(a[i].l1==y){
							if(x+a[i].l1+z==lb){
								ans[i]++;
							}
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=p;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
