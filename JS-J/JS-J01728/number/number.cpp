#include<bits/stdc++.h>
using namespace std;
int main(){
     freopen("number.in","r",stdin);
     freopen("number.out","w",stdout);
     ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
     string a;
     long long b[10]={0};
     cin>>a;
     int c=a.length();
     for(int i=0;i<c;i++){
		 if(a[i]>='0'&&a[i]<='9'){
			 int d=a[i]-'0';
			 b[d]++;
		 }
	 }
	 for(int i=9;i>=0;i--){
		 for(int j=1;j<=b[i];j++){
			 cout<<i;
		 }
	 }
     return 0;                       
}
