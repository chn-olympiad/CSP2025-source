#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long int ji[N];
int all=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string m;
	cin>>m;
	for(int i=0;i<m.size();i++){
		if(m[i]>='0'&&m[i]<='9'){
			ji[m[i]-'0']++;
//			cout<<111<<endl;
		}
	}
	for(int i=9;i>=0;i--){
		if(ji[i]==0)continue;
		else{
//			cout<<ji[i]<<endl;
			for(int j=1;j<=ji[i];j++){
				cout<<i;
			}
//			cout<<endl;
		}
	} 
	return 0;
}