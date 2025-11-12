#include<bits/stdc++.h>
using namespace std;
int bjt[11];
string n;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	int len=n.size();
	for(int i=0;i<len;i++){
		if(n[i]>='0'&&n[i]<='9'){
			bjt[n[i]-'0']++;
		}
	}
	//int op=0;
	for(int i=9;i>=0;i--){
		if(bjt[i]!=0){
			//op=1;
			for(int j=1;j<=bjt[i];j++){
				cout<<i;
			}
		}
	}
//	if(op==0&&bjt[0]!=0) cout<<"0";
//	else{
//		if(op==1&&bjt[0]!=0){
//			for(int j=1;j<=bjt[0];j++){
//				cout<<0;
//			}
//		}
//	}
	return 0;
}
//记得关注释！