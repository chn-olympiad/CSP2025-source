#include<bits/stdc++.h>	
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int sum=s.size();
    int xx[10000001]={0};
    int kk=0,max=0;
    int a[10000000000]={0};
    for(int i=0;i<=sum;i++){
		cin>>a[i];
		}
    for(int i=0;i<=sum;i++){
		for(int j=0;j<=9;j++){
			if(a[i]==j){
				cin>>xx[i];
				kk=kk+1;
				}
			}
		}
     for(int i=0;i<=kk;i++){
		 if(xx[i]>max){
			 max=xx[i];
			 }
		 }cout<<max;
     return 0;
}
