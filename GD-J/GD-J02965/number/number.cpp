#include<bits/stdc++.h>
using namespace std;
string str;
long long a[20],sum=0,num=0,l=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<20;i++) a[i]=0;
	for(int i=0;i<str.length();i++){
		if(str[i]<='9'&&str[i]>='0'){
			a[int(str[i]-'0')]++;
			num++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=0;j<a[i];j++){
				cout<<i;
//				for(int k=0;k<num-1;k++){
//					l*=10;
//				}
//				sum+=l*i;
//				l=1;
//				num--;
			}
		}
	}
	cout<<endl;
	return 0;
//	cout<<sum;
}
