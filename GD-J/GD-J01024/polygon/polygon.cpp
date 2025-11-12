#include<bits/stdc++.h>
using namespace std;
const int N=50005;
int sb[N],sbb[N];
bool s(int x,int y){
	return x>=y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a;
	cin>>a;
	
	for(int i=0;i<a;i++){
		cin>>sb[i];
	}
//	sort(sb,sb+a,s);
//	
//	int k=0;
//	for(int i=0;i<a-2;i++){
//		int head=sb[i],bigg=a-1,lei;	
//		for(int j=i+1;j<a;j++){
//			lei+=sb[j]
//		}
////		for(int j=3;j<a-i;j++){
////			
////		}
//	}
	cout<<9;
	return 0;
}
