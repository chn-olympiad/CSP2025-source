#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	int mp[10101];
	int n,a1,a2,a3,cnt=0;
	for(int i=0;i<t;i++){
		cin>>n;
		
		for(int j=0;j<n;j++){
			cin>>a1>>a2>>a3;
			if(a1>a2&&a2>=a3){
				cnt+=a1;
			}
			else if(a1>a3&&a3>=a2) cnt+=a1;
			else if(a2>a1&&a1>=a3){
				cnt+=a2;
			}
			else if(a2>a3&&a3>=a1) cnt+=a2;
			else if(a3>a1&&a1>=a2) cnt+=a3;
			else if(a3>a2&&a2>=a1){
				cnt+=a3;
			}
			
		}mp[i]=cnt;cnt=0;
		
	}
	for(int i=0;i<t;i++){
		cout<<mp[i]<<endl;
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
//Ren5Jie4Di4Ling5%

