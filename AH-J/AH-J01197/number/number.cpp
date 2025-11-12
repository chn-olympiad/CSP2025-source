#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000000],flag=0,flag1,k=-1,cnt,cntt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		for(int j='0';j<='9';j++){
		if(flag==1){
			flag=0;
			break;
		}
			if(int (s[i])==j) {
				while(1){
					k++;
					cnt++;
					a[k]=s[i]-'0';
					flag=1;
					break;
					
				}
			
			}
		}
	}
	for(int i=0;i<cnt;i++){
		for(int j=i+1;j<cnt;j++){
		if(a[i]<a[j]){
			swap(a[i],a[j]);
			}
		}	
	}
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	return 0;
}
