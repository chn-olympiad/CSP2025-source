#include<bits/stdc++.h>
using namespace std;
int b[1000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int len=a.size();
	int sum=0;
	for(int i=0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[++sum]=a[i]-'0';
		}
	}
	sort(b+1,b+1+sum);
	int flag=0;
	for(int i=sum;i>=1;i--){
		if(b[i]!=0){
			flag=1;
		}
		if(flag==1){
			cout<<b[i];
		}
	}
	return 0;
}
