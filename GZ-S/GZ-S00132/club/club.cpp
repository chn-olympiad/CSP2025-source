//GZ-S00132 遵义市第四中学 孙泽坤
#include<bits/stdc++.h> 
using namespace std;
int main(){
	int a;
	cin>>a;
	for(int i=0;i<a;i++){
		int b,n=0;
		cin>>b;
		for(int j=0;j<b;j++){
			int a1,a2,a3;
			cin>>a1>>a2>>a3;
			n+=max(max(a1,a2),a3);		
		}
		cout<<n<<endl;
	}
	return 0;
}
