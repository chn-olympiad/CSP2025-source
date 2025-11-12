#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[100000]={0},k=0;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){    
	int y=s[i];                                           
		if(y-97<0)
		 a[k++]=y-48;
	}
	sort(a,a+k);
	for(int i=k-1;i>=0;i--){
		cout<<a[i];
	}
	
	return 0;
}