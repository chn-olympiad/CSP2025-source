#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int b[11]={},sum=0,k;
	cin>>a;
	for(int i=0;;i++){
		if(a[i]==' '){
			k=i;
			break;
		}
	}
	for(int i=0;i<=k;i++){
		if(a[i]-'0'>=0&&a[i]-'0'<10)b[a[i]-'0']++;
		
	}
	for(int i=10;i>=0;i--){
		if(b[i]!=0){
			for(int x=0;x<b[i];x++)sum=sum*10+i;	
		}	
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
