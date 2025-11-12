#include<bits/stdc++.h>
using namespace std;
int a[100000][100000];
int max1(int a,int b,int c){
	int n = max(a,b);
	return max(n,c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;
	cin>>n;
	while(n>0){
		int num=0,a,b,c;
		cin>>t;
		for(int i=0;i<t;i++){
			//for(int j=0;j<3,j++){
				cin>>a>>b>>c;
				num+=max1(a,b,c);
			//}
		}
		cout<<num;
		n--;
	}
	
	
	return 0;
}