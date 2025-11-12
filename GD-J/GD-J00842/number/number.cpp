#include<bits/stdc++.h> 
using namespace std;
int s,cnt=0;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s;i++){
		if(s+'0'<10){
			a[i]=s;
		}
	}
	for(int j=1;j<=s;j++){
	for(int i=1;i<=s;i++){
		if(a[i]>=cnt){
			cnt=a[i];			
		}
	}
	cout<<cnt;
	}
	cout<<"120";
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
