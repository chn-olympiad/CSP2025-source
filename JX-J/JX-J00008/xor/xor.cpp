#include <iostream>
#include <cstring>
using namespace std;
int a,b;
int k[500050];
int cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for (int i=1;i<=a;i++){
        cin>>k[i];
	}
	for (int i=1;i<=a;i++){
        if (k[i]==b) cnt++;
	}
	cout<<cnt<<endl;
	return 0;

}
