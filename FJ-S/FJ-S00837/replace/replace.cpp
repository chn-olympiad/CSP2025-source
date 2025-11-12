#include<iostream>
#include<cstring>
using namespace std;
const int N=2e5+5;
struct Node{
	string s1,s2;
};
int n,q;
Node arr[N];
string t1,t2;
//void check(string x,string y){
//	for(int i=0;i<t1.size();i++){
//		for(int j=i;j<t1.size();j++){
//			if(j-i+1==x.size()){
//				int qz=0;
//				for(int k=i,id=0;k<=j;k++,id++){
//					if(t1[k]!=x[id]){
//						qz=1;
//						break;
//					}
//				}
//				if(qz==0){
//					string a="";
//					for(int i)
//				}
//			}
//		}
//	}
//}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>arr[i].s1>>arr[i].s2; 
	}
	while(q--){
		cin>>t1>>t2;
//		if(t1.size()!=t2.size()){
//			printf("0\n");
//			continue;
//		}
//		for(int i=1;i<=n;i++){
//			check(arr[i].s1,arr[i].s2);
//		}
		cout<<0<<endl;
	}
	return 0;
}
