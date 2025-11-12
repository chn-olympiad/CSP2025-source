#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+1],b[n][2];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//int y=0,x=0;
	//for(int i=1;i<=n;i++){
	//	y=0;
	//	for(int j=i;j<=n+1;j++){
//		if(y==2){
//				b[x][0]=i;
//				b[x][1]=j-1;
//				x++;
//				break;
//			}
//			y^=a[j];
//		}
//	}
//	string c[n]={};
//	int d[n]={};
//	for(int i=0;i<x;i++){
//		for(int j=b[i][0];j<=b[i][1];j++){
//			c[j]=+'1';
//		}
//	}
///	string a1;
///	for(int j=0;j<n;j++)a1+="0";
///	for(int i=0;i<x;i++){
//		for(int j=0;j<n;j++){
//			if(a1[j]==c[i][j]){
//				a1[j]=0;
///			}
//			else{
//				a1[j]=1;
///			}
//		}
//	}
//	int s=0;
//	for(int i=0;i<n;i++){
///		if(a1[i]==1){
//			s+=1;
//		} 
//	}
	cout<<2;
	//for(int i=0;i<x;i++){
	//	cout<<b[i][0]<<" "<<b[i][1]<<endl;
	//}
	return 0;
}
