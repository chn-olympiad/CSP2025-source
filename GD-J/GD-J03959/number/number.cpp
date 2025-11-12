#include<bits/stdc++.h>
using namespace std;
long long cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	char b[10]={'0','1','2','3','4','5','6','7','8','9'};
	long long a[1000000]={0},num=0;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<10;j++){
			if(s[i]==b[j]){
				a[i]=int(s[i])-48;
				cnt++;
				break;
			}
		}
	}
	for(int i=0;i<cnt;i++){
		for(int j=0;j<cnt-i;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=0;i<cnt;i++){
		num+=a[i]*pow(10,cnt-i-1);
	}
	cout<<num<<endl;
}
