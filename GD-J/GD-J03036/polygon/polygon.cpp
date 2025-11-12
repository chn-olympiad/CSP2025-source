//#include <bits/stdc++.h>
//using namespace std;
//int n,ans=0;	
//int a[5001];
//void ans3(){
//	int b[3];
//	b[0]=a[0];
//	int left=0;
//	while(left+2<n){
//	for(int j=left+1;j<n-1;j++){
//		b[1]=a[j];
//			for(int i=left+2;i<n;i++){
//			if(b[0]+b[1]>a[i]){
//				ans+=1;
//			}
//			else{
////				cout<<b[0]<<' '<<b[1]<<' '<<a[i];
//				break;
//			}
//		}
//	}
//	left+=1;
//	b[0]=a[left];		
//	}	
//	return;
//}
//int main(){
//	//freopen("polygon.in","r",stdin);
//	//freopen("polygon.out","w",stdout);
//	cin>>n;
//	for(int i=0;i<n;i++){
//		cin>>a[i];
//	}
//	sort(a,a+n);
//	ans3();
//	cout<<ans;
//   return 0; 
//} 
#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	int a[11];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int _1=0;_1+2<n;_1++){
	 	for(int _2=_1+1;_2+1<n;_2++){
	 		for(int _3=_2+1;_3<n;_3++){
	 			if(a[_1]+a[_2]>a[_3]){
	 				cout<<a[_1]<<' '<<a[_2]<<' '<<a[_3]<<endl;
					 ans+=1;
				 }
				 else{
				 	break;
				 }
			 }
		 } 
	}
	cout<<ans;
} 
