#include<iostream>
#include<string>
using namespace std;
string A;
int Cnt[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>> A;
	for(int i=0;i < A.size();i++){
		if(A[i]>='0'&&A[i]<='9')Cnt[(A[i]-'0')]++;
	}
	for(int i=9;i >=0;i--){
		while(Cnt[i]>0){
			cout<<i;
			Cnt[i]--;
		}
	}
	return 0;
}
