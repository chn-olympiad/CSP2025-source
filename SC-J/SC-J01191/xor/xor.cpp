/*
枚举开头和结尾

在这之间取异或和
如果=k
总量+1 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[500001],k;
int f,bj[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int s=0; 
			for(int i=l;i<=r;i++){
				if(bj[i]==1){
					s=-1;
					break;
				}
				s=s^a[i];
			}
			if(s==k){
				f++;
				//cout<<"以"<<l<<"为开头"<<r<<"为结尾可行(s="<<s<<")\n"; 
				for(int i=l;i<=r;i++){
					bj[i]=1;
				}
			}
			else if(s==-1){
				//cout<<"以"<<l<<"为开头"<<r<<"为结尾重叠\n"; 
			}
		}
	}
	cout<<f;
	return 0;
}
