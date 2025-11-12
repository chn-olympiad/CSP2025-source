#include<bits/stdc++.h>
using namespace std;
string a;
int tong[10]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)if(a[i]>='0' and a[i]<='9')tong[a[i]-'0']++;
//	for(int i=0;i<=9;i++)cout<<i<<" "<<tong[i]<<endl;
	for(int i=9;i>=0;i--){
		while(tong[i]!=0){
			cout<<i;
			tong[i]--;
		}
	}
	return 0;
}
