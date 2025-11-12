#include<bits/stdc++.h>
using namespace std;
//int a,c[10000],c1=0,num=0;
//int b[10000];
//int book[10000];
//bool sbx(){
//	sort(c+1,c+c1+1);
//	cout<< "<<<<";
//	for(int i=1;i<=c1;i++){
//		cout<<c[i];
//	}
//	cout<<">>>>";
//	int ans=0;
//	for(int i=1;i<c1;i++){
//		ans+=c[i];
//	}
//	if(ans>c[c1]){
//		return true;
//	}
//	return false;
//}
//void dfs(int m){
//	if(c1>=a){
//		return;
//	}
//	for(int i=a;i>=1;i--){
//		if(book[i]==0){
//			cout<<"*"<<book[1];
//			c1++;
//			c[c1]=b[i];
//			book[i]=1;
//			if(sbx()&&c1>=3){
//				num++;
//				for(int j=1;j<=c1;j++){
//					cout<<c[j];
//				}
//				cout<<' ';
//				book[i]=1;
//				dfs(i+1);
//				book[i]=0;
//				c1--;
//				continue;
//			}else{
//					book[i]=1;
//					dfs(i+1);
//					continue;
//			}			
//		}
//	}
//}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,b[10000];
	int num=0;
    cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b[i];
	} 
	if(a==1||a==2){
		cout<<0;
		return 0;
	}else{
		sort(b+1,b+1+a);
		if(b[1]+b[2]>b[3]){
			num++;
		}	
		
	}
	cout<<num;
	return 0;
//	dfs(1);
//	cout<<num;
//	
} 